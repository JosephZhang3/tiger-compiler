#include "string.h"
#include "stdio.h"
#include "AVL_FBBST.h"

int main()
{
    // string chars[] = {"s","p","i","p","f","b","s","t","r"};
    string chars[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    AVLTree t = NULL;
    for (int i = 0; i < 9; i++)
    {
        t = AVLInsert(t, chars[i]);
    }

    printf("start print================\n");
    printTreeBranch(t, 1);
    printf("\n\n");
}