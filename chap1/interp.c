#include "interp.h"

/** 解释器的辅助临时数据结构：表 */
Table_ Table(string id, int value, struct table *tail){
    Table_ t = checked_malloc(sizeof(*t));
    t->id=id;
    t->value=value;
    t->tail=tail;
    return t;
}

IntAndTable_ intAndTable(int i, Table_ t){
    IntAndTable_ it = checked_malloc(sizeof(*it));
    it->i = i;
    it->t = t;
    return it;
}

/** 解释直线式程序（函数式写法） */
void interp(A_stm s){
    
}

Table_ interpStm(A_stm s, Table_ t){
     if(s->kind == A_compoundStm){
        interpStm(s->u.compound.stm1, t);
        interpStm(s->u.compound.stm2, t);
     }
     if(s->kind == A_assignStm){
        t->tail = t;
        t->id = s->u.assign.id;
        t->value = interpExp(s->u.assign.exp, t)->value;
     }
     if(s->kind == A_printStm){
// s->u.print.exps
     }
}

void update(Table_ t, string i, int value){
    
}

int lookup(Table_ t, string key){
    
}

Table_ interpExp(A_exp e, Table_ t){

}
