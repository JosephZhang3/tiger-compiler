#include "interp.h"
#include "stdio.h"
#include "string.h"

/**
 * 解释器 interpreter 的辅助数据结构：表
 * id, value, pointer to next table ceil
 */
IntAndTable_ IntAndTable(int value, Table_ t)
{
    IntAndTable_ it = checked_malloc(sizeof(*it));
    it->i = value;
    it->t = t;
    return it;
}

/** 解释直线式程序（函数式写法）。注意：声明局部变量的同时对它进行初始化，初始化后不要再更新它！ */
void interp(A_stm s)
{
    Table_ finalR = interpStm(s, NULL);
    printf("Program right finished.");
}

/** interpret statement 解释语句 */
Table_ interpStm(A_stm s, Table_ t)
{
    if (s->kind == A_compoundStm)
    {
        t = interpStm(s->u.compound.stm1, t);
        t = interpStm(s->u.compound.stm2, t);
    }
    if (s->kind == A_assignStm)
    {
        IntAndTable_ it = interpExp(s->u.assign.exp, t);
        t = update(t, s->u.assign.id, it->i);
    }
    if (s->kind == A_printStm)
    {
        t = printExpList(s->u.print.exps, t);
    }
    return t;
}

Table_ update(Table_ t, string i, int value)
{
    // 把原先的表 t 作为 tail 拼接到新表
    return Table(i, value, t);
}

/** 根据id（也就是变量名称），从table中查找对应的值 沿链表往更深处搜索即可 */
int lookup(Table_ t, string key)
{
    if (t == NULL)
    {
        assert("The table t should not be NULL !");
    }

    if (strcmp(t->id, key) == 0)
    {
        return t->value;
    }
    else
    {
        lookup(t->tail, key);
    }
}

/** interpret expression 解释表达式 */
IntAndTable_ interpExp(A_exp e, Table_ t)
{
    int i;       // 中间临时计算结果
    Table_ newT; // 被 计算/赋值 等的副作用影响后产生的新表

    if (e->kind == A_idExp)
    {
        i = lookup(t, e->u.id);
        newT = t; // 无副作用，不生成新的变量表
    }
    else if (e->kind == A_numExp)
    {
        i = e->u.num;
        newT = t; // 无副作用，不生成新的变量表
    }
    else if (e->kind == A_opExp)
    {
        IntAndTable_ leftIt = interpExp(e->u.op.left, t);
        IntAndTable_ rightIt = interpExp(e->u.op.right, leftIt->t); // 约定从左到右的计算顺序，左子表达式的结果应用到右边
        t = rightIt->t;                                             // 对 左 和 右 两个子表达式求值可能分别地产生副作用，接收新的变量表
        int leftResult = leftIt->i;
        int rightResult = rightIt->i;
        int opResult;
        if (e->u.op.oper == A_plus)
        {
            opResult = leftResult + rightResult;
        }
        else if (e->u.op.oper == A_minus)
        {
            opResult = leftResult - rightResult;
        }
        else if (e->u.op.oper == A_times)
        {
            opResult = leftResult * rightResult;
        }
        else if (e->u.op.oper == A_div)
        {
            opResult = leftResult / rightResult;
        }
        i = opResult;
        newT = t;
    }
    else if (e->kind = A_eseqExp)
    {
        newT = interpStm(e->u.eseq.stm, t);
        IntAndTable_ tempResult = interpExp(e->u.eseq.exp, newT);
        newT = tempResult->t; // 进一步递归解释表达式可能产生副作用
        i = tempResult->i;
    }
    else
    {
        assert("Unrecognized expression type !");
    }
    IntAndTable_ newIt = IntAndTable(i, newT);
    return newIt;
}

/**
 * 表达式列表是嵌套结构，所以递归处理
 * 解释表达式列表不需要记录中间结果，即不需要用 IntAndTable_ 盛放中间结果，
 * 因为在递归地解释其中的表达式时，就已经把副作用（对变量的修改）记录到 Table_ 中了，
 * 递归时传递 Table_ 然后返回即可
 */
Table_ printExpList(A_expList elist, Table_ t)
{
    if (elist->kind == A_lastExpList)
    {
        IntAndTable_ interpResult = interpExp(elist->u.last, t);
        printf("Execute print : %d\n", interpResult->i);
    }
    else
    {
        IntAndTable_ interpResult = interpExp(elist->u.pair.head, t);
        printf("Execute print : %d\n", interpResult->i);
        t = printExpList(elist->u.pair.tail, interpResult->t);
    }

    return t;
}