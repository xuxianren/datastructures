#ifndef _DisjSet_H
typedef int * DisjSet;

DisjSet Initiliaze(int size);
void SetUnion(DisjSet s, int root1, int root2);
int Find(DisjSet s, int x);

#endif

