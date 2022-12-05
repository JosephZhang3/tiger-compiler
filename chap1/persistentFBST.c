/** 
长效的函数式二叉搜索树
persistent functional binary search tree
*/
#include "persistentFBST.h"
#include "string.h"

T_tree Tree(T_tree l, string key, T_tree r){
    T_tree t = checked_malloc(sizeof(*t));
    t->left = l;
    t->key = key;
    t->right = r;
    return t;
}

T_tree insert(string key, T_tree t){
    if(t==NULL){
        // 空树，插入首个分叉点
        return Tree(NULL, key, NULL);
    }else if(strcmp(key, t->key) < 0){
        // 遍历左子树插入
        return Tree(insert(key, t->left),
                    t->key, 
                    t->right);
    }else if(strcmp(key, t->key) > 0){
        // 遍历右子树插入
        return Tree(
                    t->left,
                    t->key,
                    insert(key, t->right)
        );
    }else {
        return Tree(t->left, key, t->right);
    }
}

bool member(string key, T_tree t){
    if(t == NULL){
        return FALSE;
    }
    switch(strcmp(key, t->key)){
        case -1:
            return member(key, t->left);
        case 1:
            return member(key, t->right);
        case 0:
            return TRUE;
        default:
            assert("Some thing error when switch iterate!");
    }
}