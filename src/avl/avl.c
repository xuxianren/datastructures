#include <stdlib.h>
#include "avl.h"

struct AvlNode {
  ElementType Element;
  AvlTree Left;
  AvlTree Right;
  int Height;
};


AvlTree Insert(ElementType X, AvlTree T){
    AvlTree parent;
    for(AvlTree node=T; node != NULL;) {
        parent = node;
        if (X < node->Element) {
            node = node->Left;
        } else {
            node = node->Right;
        }
    // 创建node


    // 插入node
    if (parent == NULL) {
        return ;
    }

    // 更新节点高度, 如果相差大于2
    while (parent != NULL){
        parent->Height = Max(parent->Left->Height, parent->Right->Height);



    }

    // 3+4重构 调整位置和高度
    if (node) {
        // LL
        // LR
        // RL
        // RR 
        if (Height(node->Left) < Height(node->Right)){
        }
    }
}

AvlTree Justify(){

}

AvlTree Delete(ElementType X, AvlTree T){

}