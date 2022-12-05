#include "max_args.h"

/** 给定语句中任意子表达式内的print语句的参数个数的最大值
思路：由于有嵌套，肯定要使用递归，每找到一个print语句，就拿它的参数个数
跟暂存的max值做比较
*/
int max(int a, int b){
    return (a > b) ? a:b;
}

int maxargs_exp(A_exp el){
    switch(el->kind){
    case A_idExp:
        // countExps() 计数1，然后有max()计算，
        // 如果语句包含 printStm，保底结果为1，所以此处返回0
        // 如果语句不包含 printStm，则走入 case A_assignStm:  接着 maxargs_exp 计算得到此处返回的0
        return 0;
    case A_numExp:
        return 0;
    case A_opExp:
        return max(maxargs_exp(el->u.op.left), maxargs_exp(el->u.op.right));
    case A_eseqExp:
        return max(maxargs(el->u.eseq.stm), maxargs_exp(el->u.eseq.exp));
    default:
        assert("Wrong kind of params A_exp !");
    }
}

int maxargs_expList(A_expList el){
    switch(el->kind){
    case A_lastExpList:
        return maxargs_exp(el->u.last);
    case A_pairExpList:
        return max(maxargs_expList(el->u.pair.tail), maxargs_exp(el->u.pair.head));
    default:
        assert("Wrong kind of param A_expList !");
    }
}

int countExps(A_expList eList){
    int count = 1;
    // 只要发现tail尾元素还是一个list，就继续沿着链表查找
    for(; eList->kind == A_pairExpList; eList = eList->u.pair.tail){
        count++;
    }
    return count;
}

int maxargs(A_stm s){
    switch(s->kind){
    case A_printStm:// 期望的终止点
        return max(
            countExps(s->u.print.exps), 
            maxargs_expList(s->u.print.exps)
            );
    case A_assignStm:
        return maxargs_exp(s->u.assign.exp);
    case A_compoundStm:
        return max(
            maxargs(s->u.compound.stm1),
            maxargs(s->u.compound.stm2)
            );
    default:
        assert("Wrong kind of param A_stm !");
    }
}