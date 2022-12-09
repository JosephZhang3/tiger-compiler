/**
习题*d
functional balanced binary search tree
函数式平衡二叉搜索树，插入时而不是查找时保持树的平衡

TODO FIXME 如果输入是乱序的序列，可以保持平衡，但是如果是顺序的，比如从 a 到 z ，一开始形成的树就退化成了链表。问题出在哪?
可能原因：
1. tree结构体记录的是树高度，不是平衡因子
2. 超出限度的判定或者处理函数有错误

reference: https://blog.csdn.net/Yusamm/article/details/105720509
*/
#include "AVL_FBBST.h"
#include "stdlib.h"
int count = 0;
#define NEED_REBALANCE_HEIGHT 2

/** 从控制台的输出构造一棵平衡二叉树 N为节点数量 */
AVLTree makeAVL(int N)
{
    AVLTree t = NULL;
    string key;
    while (N--)
    {
        scanf("%s", &key);
        AVLInsert(t, key);
    }
    return t;
}

void freeTree(AVLTree t)
{
    if (t->left)
    { // 如果左子树存在，不是NULL
        freeTree(t->left);
    }
    if (t->right)
    {
        freeTree(t->right);
    }
    free(t);
}

int get_max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int get_height(AVLTree t)
{
    if (!t)
    { // t为NULL则树高不存在，这点无法通过构造函数确定，需要注意
        return -1;
    }
    return t->height;
}

void printIndent(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("   ");
    }
}

AVLTree AVLInsert(AVLTree t, string key)
{
    printIndent(count++);
    printf(" | entry with key: %s | ", key);
    if (t == NULL)
    {
        t = checked_malloc(sizeof(*t));
        t->left = t->right = NULL;
        t->height = 0;
        t->key = key;
    }
    else
    {
        if (strcmp(key, t->key) < 0)
        {
            t->left = AVLInsert(t->left, key);
            if (get_height(t->left) - get_height(t->right) == NEED_REBALANCE_HEIGHT)
            {
                if (strcmp(key, t->left->key) > 0)
                {
                    // 破坏点在左子树的右子树上，双旋，先右旋再左旋
                    t = right_left_rotate(t);
                }
                else
                {
                    // 破坏点在左子树的左子树上，简单左旋
                    t = left_rotate(t);
                }
            }
        }
        else if (strcmp(key, t->key) > 0)
        {
            t->right = AVLInsert(t->right, key);
            if (get_height(t->right) - get_height(t->left) == NEED_REBALANCE_HEIGHT)
            {
                if (strcmp(key, t->right->key) < 0)
                {
                    // 破坏点在右子树的左子树上，双旋，先左旋再右旋
                    t = left_right_rotate(t);
                }
                else
                {
                    // 破坏点在右子树的右子树上，简单右旋
                    t = right_rotate(t);
                }
            }
        }
        else
        {
        }
    }
    t->height = get_max(get_height(t->left), get_height(t->right)) + 1;
    printIndent(--count);
    printf(" return [t key %s height %d]\n\n\n", t->key, t->height);
    return t;
}

/**
左单旋转
*/
AVLTree left_rotate(AVLTree t)
{
    AVLTree b = t->left;
    t->left = b->right;
    b->right = t;

    // 更新 t b 的树高
    t->height = get_max(get_height(t->left), get_height(t->right));
    b->height = get_max(get_height(b->left), get_height(b->right));
    return b; // b 取代原先 t 的位置
}

/**
右单旋转
*/
AVLTree right_rotate(AVLTree t)
{
    AVLTree b = t->right;
    t->right = b->left;
    b->left = t;

    // 更新 t b 的树高
    t->height = get_max(get_height(t->left), get_height(t->right));
    b->height = get_max(get_height(b->left), get_height(b->right));
    return b; // b 取代原先 t 的位置
}

/**
左右双旋，先左子树右旋，然后自身左旋
*/
AVLTree right_left_rotate(AVLTree t)
{
    t->left = right_rotate(t->left);
    return left_rotate(t);
}

/**
右左双旋，镜像操作，调反
*/
AVLTree left_right_rotate(AVLTree t)
{
    t->right = left_rotate(t->right);
    return right_rotate(t);
}

bool member(string key, AVLTree t)
{
}

void printTreeBranch(AVLTree t, int layer)
{
    if (t->right)
    {
        printTreeBranch(t->right, layer + 1);
    }

    printf("-----");
    for (int i = 1; i < layer; i++)
    {
        printf("-----");
    }
    printf("%s\n", t->key); // 递归终点，不再继续调用自身

    if (t->left)
    {
        printTreeBranch(t->left, layer + 1);
    }
}