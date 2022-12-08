#ifndef BBST_H
#define BBST_H

#include "util.h"
#include "stdio.h"
#include "string.h"

#define LH 1
#define EH 0
#define RH -1

typedef struct BBST_node {
    struct BBST_node *left;// 左子树
    string key;// 分叉节点
    struct BBST_node *right;// 右子树
    int bf;// 平衡因子 balance factor

// bf值代表的3种状态
// （1）0：初始状态：插入结束
// （2）-1/1：调整 bf 的过程向上蔓延 处于这种状态，下一步就需要继续向上调整其余节点的bf，current node 和 parent 也同步向上移动
// （3 ）-2/2：失去了平衡，需要进行修复
}*BBST_tree, BBST_node;

int insert();

bool member(string key, BBST_tree* t);

void printTreeBranch(BBST_tree* t, int layer);

#endif