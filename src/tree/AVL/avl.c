#include "avl.h"

#include <stdio.h>
#include <stdlib.h>

static int Max(int a, int b) { return a > b ? a : b; }
static int Min(int a, int b) { return a > b ? b : a; }

static int Height(Position P) {
  if (P == NULL) {
    return -1;
  } else {
    return P->Height;
  }
};

AvlTree MakeEmpty(AvlTree T) {
  if (T != NULL) {
    MakeEmpty(T->Left);
    MakeEmpty(T->Right);
    free(T);
  }
  return NULL;
}
/*
WithXX 表示和XX进行交换
 */

static Position SingleRotateWithLeft(Position K2) {
  Position K1;
  K1 = K2->Left;
  K2->Left = K1->Right;
  K1->Right = K2;
  K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
  K1->Height = Max(Height(K1->Left), K2->Height) + 1;
  return K1;
}

static Position SingleRotateWithRight(Position K1) {
  Position K2;
  K2 = K1->Right;
  K1->Right = K2->Left;
  K2->Left = K1;
  K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
  K2->Height = Max(K1->Height, Height(K2->Right)) + 1;
  return K2;
}

static Position DoubleRotateWithLeft(Position K3) {
  K3->Left = SingleRotateWithRight(K3->Left);
  return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K1) {
  K1->Right = SingleRotateWithLeft(K1->Right);
  return SingleRotateWithRight(K1);
}

AvlTree Insert(ElementType X, AvlTree T) {
  if (T == NULL) {
    T = malloc(sizeof(struct AvlNode));
    if (T == NULL) {
      //   FatalError("Out of space!!!");
      printf("Out of space!!!");
    } else {
      T->Element = X;
      T->Height = 0;
      T->Left = T->Right = NULL;
    }
  } else if (X < T->Element) {
    T->Left = Insert(X, T->Left);
    if (Height(T->Left) - Height(T->Right) == 2) {
      if (X < T->Left->Element)
        T = SingleRotateWithLeft(T);
      else
        T = DoubleRotateWithLeft(T);
    }
  } else if (X > T->Element) {
    T->Right = Insert(X, T->Right);
    if (Height(T->Right) - Height(T->Left) == 2)
      if (X > T->Right->Element)
        T = SingleRotateWithRight(T);
      else
        T = DoubleRotateWithRight(T);
  }
  T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
  return T;
}

void LDR(AvlTree T) {
  if (T != NULL) {
    LDR(T->Left);
    printf("%d  ", T->Element);
    LDR(T->Right);
  }
}
int Retrieve(Position P) { return P->Element; }