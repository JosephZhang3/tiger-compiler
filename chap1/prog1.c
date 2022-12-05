#include "prog1.h"

/** 
程序的树表示，可以debug观察结构体中内容
源代码 和 AST 之间的转换，可以看作一种复杂的反序列化和序列化
忽略源代码每行首尾的空格，它就是一长串包含了“逻辑”的字符串
*/
A_stm prog(void){
    // 最终表示  a := 5 + 3 ; b := (print(a, a - 1 ), 10 * a) ; print(b)
    return  A_CompoundStm(// ; 组装复合语句
                // a := 5 + 3
                A_AssignStm("a", A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),

                A_CompoundStm(// ; 组装复合语句
                    // b := (print(a, a - 1 ), 10 * a)
                    A_AssignStm("b",
                        A_EseqExp(// , 分割表达式序列  b := (表达式序列)
                            // print(55, a, a - 1)
                            A_PrintStm(
                                // 55, a, a - 1  表达式列表即 print(表达式列表)
                                A_PairExpList(
                                    A_NumExp(55),
                                    // a, a - 1
                                    A_PairExpList(
                                        A_IdExp("a"),
                                        A_LastExpList(
                                            // a - 1
                                            A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1))
                                        )
                                    )
                                )
                            ),
                            // 10 * a
                            A_OpExp(A_NumExp(10), A_times, A_IdExp("a"))
                        )
                    ),
                    // print(b)
                    A_PrintStm(A_LastExpList(A_IdExp("b")))
                )
    );
}