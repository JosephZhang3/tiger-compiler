#include "max_args.h"

/** 解释表达式时用的数据结构（返回int且有副作用） */
typedef struct intAndTable *IntAndTable_;
struct intAndTable {
    int i;
    Table_ t;
};
IntAndTable_ IntAndTable(int i, Table_ t);