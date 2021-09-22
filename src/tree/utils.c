#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef struct Node* Tree;
typedef struct Node* Position;

struct Node {
  ElementType Element;
  Tree Left;
  Tree Right;
};

int Height(Tree T) {}

char* IntMediate(int X, int width) {
  int max = 1;
  for (int i = 1; i < width; i++) {
    max *= 9;
  }
  if (X < max) {
    return NULL;
  } else {
    char* fmt = "%ld";
    char* str = malloc(width + 1);
    sprintf(str, "\d");
  }
}

void PrintTree(Tree T, int offset) {
  if (T == NULL) {
    return NULL;
  }
  for (int i = 0; i < offset; i++) {
    printf(" ");
  }
  printf("%d\n", T->Element);
  if (T->Left != NULL & T->Right != NULL) {
    for (int i = 0; i < offset - 1; i++) {
      printf(" ");
    }
    printf("/");
  }
  if (T->Right != NULL) {
  }
  printf("\n");
  PrintTree(T->Left, offset - 2);
  PrintTree(T->Right, offset + 2);
}

int main(int argc, char const* argv[]) {
  /* code */
  printf("    10    \n");
  printf("   /  \\  \n");
  printf("  8    13 \n");
  return 0;
}
