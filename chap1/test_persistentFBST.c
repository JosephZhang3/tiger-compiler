#include "string.h"
#include "stdio.h"
#include "persistentFBST.h"

int main(){
    T_tree t = NULL;
    t = insert("f", t);
    t = insert("j", t);
    t = insert("a", t);
    t = insert("x", t);
    t = insert("e", t);
    t = insert("m", t);
    printTreeBranch(t, 1);
    printf("\n");
    printf("\n");

    bool flag = member("x",t);
    printf("The member search result is %d\n", flag);
    bool f = member("z",t);
    printf("The member search result is %d\n", f);
    printf("\n");
    printf("\n");

    T_tree t2 = NULL;
    t2 = insert("t", t2);
    t2 = insert("s", t2);
    t2 = insert("p", t2);
    t2 = insert("i", t2);
    t2 = insert("p", t2);
    t2 = insert("f", t2);
    t2 = insert("b", t2);
    t2 = insert("s", t2);
    t2 = insert("t", t2);
    printTreeBranch(t2, 1);
    printf("\n");
    printf("\n");

    T_tree t3 = NULL;
    t3 = insert("a", t3);
    t3 = insert("b", t3);
    t3 = insert("c", t3);
    t3 = insert("d", t3);
    t3 = insert("e", t3);
    t3 = insert("f", t3);
    t3 = insert("g", t3);
    t3 = insert("h", t3);
    t3 = insert("i", t3);
    printTreeBranch(t3, 1);
    printf("\n");
    printf("\n");
}