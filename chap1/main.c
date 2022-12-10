#include "stdio.h"
#include "max_args.h"
#include "interp.h"
#include "prog1.h"

int main(){
    int i;
    printf("result is %d\n", !i);// NULL 与 1 与 FALSE 等价

    int r = maxargs(prog());
    printf("The max params count of print of prog1 is %d\n", r);

    interp(prog());
}