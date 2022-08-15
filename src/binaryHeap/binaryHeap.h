#ifndef _BinaryHeap_H
struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;
PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int x, PriorityQueue H);
int DeleteMin(PriorityQueue H);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
#endif

struct HeapStruct
{
    int Capacity;
    int Size;
    int * Elements;
};
