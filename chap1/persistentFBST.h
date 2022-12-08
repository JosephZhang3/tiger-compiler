#ifndef PERSISTENT_FBST_H
#define PERSISTENT_FBST_H

#include "util.h"

typedef struct tree *T_tree;
struct tree {
    T_tree left;// 左子树
    string key;// 分叉节点
    T_tree right;// 右子树
};
T_tree Tree(T_tree l, string key, T_tree r);

T_tree insert(string key, T_tree t);

bool member(string key, T_tree t);

void printTreeBranch(T_tree t, int layer);

#endif