#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main() {
  AvlTree T = MakeEmpty(NULL);
  int elements[10] = {10, 11, 13, 17, 19, 20, 21, 22, 6, 8};
  //   int elements[3] = {10, 11, 13};
  int i = 0;
  for (i = 0; i < 10; i++) {
    T = Insert(elements[i], T);
  };
  //   printf("i = %d\n", i);
  LDR(T);
  return 0;
}