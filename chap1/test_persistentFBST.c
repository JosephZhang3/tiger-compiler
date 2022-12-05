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
    bool flag = member("x",t);
    printf("The member search result is %d\n", flag);
    bool f = member("z",t);
    printf("The member search result is %d\n", f);
}