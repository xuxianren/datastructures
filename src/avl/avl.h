#ifndef _AvlTree_H
struct AvlNode;

typedef int ElementType;
/*
Postion对应节点，AvlTree对应树根节点
二者都是指针，这意味着其可能为NULL
 */
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

// 释放一颗树
AvlTree MakeEmpty(AvlTree T);

Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);

// 返回该节点的值
ElementType Retrieve(Position P);

// 遍历

void LDR(AvlTree T);

#endif

struct AvlNode {
  ElementType Element;
  AvlTree Left;
  AvlTree Right;
  int Height;
};
