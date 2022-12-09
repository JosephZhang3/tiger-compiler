#ifndef PERSISTENT_FBST_H
#define PERSISTENT_FBST_H

#include "util.h"

typedef struct keyvalue *KeyValue;
struct keyvalue
{
    string key;
    string value;
};
KeyValue KValue(string key, string value);

typedef struct tree *T_tree;
struct tree
{
    T_tree left;  // 左子树
    KeyValue kv;  // 分叉节点(键值绑定)，比较时仅针对键
    T_tree right; // 右子树
};
T_tree Tree(T_tree l, KeyValue kv, T_tree r);

T_tree insert(KeyValue kv, T_tree t);

bool member(string key, T_tree t);

void printTreeBranch(T_tree t, int layer);

#endif