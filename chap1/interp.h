#ifndef INTERP_H
#define INTERP_H

#include "max_args.h"

/** 解释表达式时用的数据结构（返回int且有副作用） */
typedef struct intAndTable *IntAndTable_;
struct intAndTable
{
    int i;
    Table_ t;
};
IntAndTable_ IntAndTable(int i, Table_ t);

void interp(A_stm s);

Table_ interpStm(A_stm s, Table_ t);

Table_ update(Table_ t, string i, int value);

int lookup(Table_ t, string key);

IntAndTable_ interpExp(A_exp e, Table_ t);

Table_ printExpList(A_expList elist, Table_ t);

#endif