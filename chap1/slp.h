/**
straight line program 直线式程序的数据结构表示

struct 首字母小写，以 _ 结尾
构造函数首字母大写

每个构造函数构造一项文法规则
*/
#ifndef SLP_H
#define SLP_H

#include "util.h"

// typedef char *string; // variable(type of string)
typedef struct A_stm_ *A_stm; // statement
typedef struct A_exp_ *A_exp; // expression
typedef struct A_expList_ *A_expList; // expression list
typedef enum {A_plus, A_minus, A_times, A_div} A_binop; // binary operation 二元操作 加减乘除

/** statement data structure */
struct A_stm_ {
    enum {A_compoundStm, A_assignStm, A_printStm} kind; // 3种语句类型，复合语句、赋值语句、打印语句
    union {
           struct {A_stm stm1, stm2;} compound; // 复合语句，组合 stm1 stm2 两个语句
           struct {string id; A_exp exp;} assign; // 赋值语句，先定义一个变量名为id，然后用一个表达式给它赋值
           struct {A_expList exps;} print; // 打印语句，逐个输出列表中各个表达式的计算结果
          } u;
};
A_stm A_CompoundStm(A_stm stm1, A_stm stm2); // 复合语句的构造函数，由多个表达式嵌套组合成
A_stm A_AssignStm(string id, A_exp exp); // 赋值语句的构造函数，由一个变量和一个表达式构成
A_stm A_PrintStm(A_expList exps); // 打印语句的构造函数，由一个表达式列表构成

/** expression data structure */
struct A_exp_ {
    enum {A_idExp, A_numExp, A_opExp, A_eseqExp} kind; // 4中表达式类型，标识符表达式（id）、值表达式（num）、操作符表达式（operation）、表达式序列（expression sequence）
    union {
           string id;
           int num;
           struct {A_exp left; A_binop oper; A_exp right;} op; // 操作符表达式的结构定义，引用了其它结构定义如 A_binop ，包括自身： A_exp
           struct {A_stm stm; A_exp exp;} eseq; // 表达式序列，组成一条语句，里面可以再嵌套语句，语句里再嵌套表达式... 如 print(a - 1, b - 2, c - 3)，其中 a - 1, b - 2, c - 3 就是一个表达式序列
          } u;
};
A_exp A_IdExp(string id);
A_exp A_NumExp(int num);
A_exp A_OpExp(A_exp left, A_binop oper, A_exp right);
A_exp A_EseqExp(A_stm stm, A_exp exp);

/** 
expression list(not expression sequence !) data structure 
注意这是一个链表结构
TODO 为什么这么定义？
*/
struct A_expList_ {
    enum {A_pairExpList, A_lastExpList} kind;
    union {
           // 联合2个结构体，why？TODO
           struct {A_exp head; A_expList tail;} pair;
           A_exp last;
          } u;
};
A_expList A_PairExpList(A_exp head, A_expList tail);
A_expList A_LastExpList(A_exp last); // 名为list，实际上构造出只有一个表达式的结构体

#endif