#include <stdlib.h>
#include "disjSet.h"

DisjSet Initiliaze(int size)
{
    DisjSet s = (DisjSet)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        s[i] = -1;
    }
    return s;
}

void SetUnion(DisjSet s, int root1, int root2)
{
    if (s[root1] < s[root2])
    {
        s[root1] = s[root1] + s[root2];
        s[root2] = root1;
    }
    else
    {
        s[root2] = s[root1] + s[root2];
        s[root1] = root2;
    }
}

int Find(DisjSet s, int x)
{
    int root = x;
    int tmp;
    while (s[root] >= 0){
        root = s[root];
    }
    while (x != root) {
        tmp = s[x];
        s[x] = root;
        x = tmp;
    }
    return root;
}