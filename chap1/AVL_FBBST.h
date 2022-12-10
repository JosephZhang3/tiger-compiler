#ifndef FBBST_H
#define FBBST_H

#include "util.h"
#include "stdio.h"
#include "string.h"

#define LH 1
#define EH 0
#define RH -1

typedef struct TreeNode *AVLTree;
struct TreeNode
{
    AVLTree left;  // 左子树
    string key;    // 分叉节点
    AVLTree right; // 右子树
    int height;    // 平衡因子 balance factor 即左右子树高度之差
};

AVLTree left_rotate(AVLTree t);

AVLTree right_rotate(AVLTree t);

AVLTree right_left_rotate(AVLTree t);

AVLTree left_right_rotate(AVLTree t);

AVLTree AVLInsert(AVLTree t, string key);

bool member(string key, AVLTree t);

void printTreeBranch(AVLTree t, int layer);

#endif