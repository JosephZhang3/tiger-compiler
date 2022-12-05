/** 凡是被嵌套引用的头文件，都要用 ifndef endif 包围，让编译器遇到重复定义时跳过 */
#ifndef MAX_ARGS_H
#define MAX_ARGS_H

#include "slp.h"

typedef struct table *Table_;
struct table {
    string id;
    int value;
    Table_ tail;
};
Table_ Table(string id, int value, struct table *tail);

int maxargs(A_stm s);

#endif