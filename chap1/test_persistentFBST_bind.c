#include "string.h"
#include "stdio.h"
#include "persistentFBST_bind.h"

int main(){
    T_tree t = NULL;
    t = insert(KValue("f","struct"), t);
    t = insert(KValue("j","union"), t);
    t = insert(KValue("a","enum"), t);
    t = insert(KValue("x","typedef"), t);
    t = insert(KValue("e","sizeof"), t);

    t = insert(KValue("m","auto"), t);
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
    t2 = insert(KValue("t","static"), t2);
    t2 = insert(KValue("s","register"), t2);
    t2 = insert(KValue("p","extern"), t2);
    t2 = insert(KValue("i","const"), t2);
    t2 = insert(KValue("p","volatile"), t2);
    t2 = insert(KValue("f","return"), t2);
    t2 = insert(KValue("b","continue"), t2);
    t2 = insert(KValue("s","break"), t2);
    t2 = insert(KValue("t","goto"), t2);
    printTreeBranch(t2, 1);
    printf("\n");
    printf("\n");
}