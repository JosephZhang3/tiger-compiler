/**
习题*d
functional balanced binary search Create
函数式平衡二叉搜索树，插入时而不是查找时保持树的平衡
*/
#include "FBBST.h"
#include "stdlib.h"

BBST_tree Create(BBST_tree* l, string key, BBST_tree* r){
    BBST_tree t = checked_malloc(sizeof(*t));
    t->left = *l;
    t->key = key;
    t->right = *r;
    t->bf = 0;
    return t;
}

/**
taller 给树增加节点后，树的高度有没有增长，如果增长了，就要判断是否失衡及进行平衡调整
*/
int insert(){
    
}

void left_rotate(BBST_tree* t){

}

void right_rotate(BBST_tree* t){

}

void left_balance(BBST_tree* t){
    // 左左失衡
    // 左右失衡
}

void right_balance(BBST_tree* t){
// 右右失衡
// 右左失衡
}

bool member(string key, BBST_tree* t){

}

void printTreeBranch(BBST_tree* t, int layer){
    if(&(*t)->right){
	   printTreeBranch(&(*t)->right,layer+1);
	}

	printf("-----");
	for(int i=1;i<layer;i++){
	   printf("-----");
    }
	printf("%s\n",&(*t)->key);// 递归终点，不再继续调用自身

	if(&(*t)->left){
	   printTreeBranch(&(*t)->left,layer+1);
	}
}