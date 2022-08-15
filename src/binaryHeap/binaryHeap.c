#include <stdio.h>
#include <stdlib.h>
#include "binaryHeap.h"

void FatalError(const char *s, int status)
{
    printf(s);
    exit(status);
}

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
    {
        FatalError("Out of space!!!", 1);
    }
    H->Elements = malloc(sizeof(int) * (MaxElements + 1));
    if (H->Elements == NULL)
    {
        FatalError("Out of space!!!", 1);
    }
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = -1;
    return H;
}

void Destroy(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}

void MakeEmpty(PriorityQueue H)
{
    H->Size = 0;
    return;
}

void Insert(int x, PriorityQueue H)
{
    int i;
    if (IsFull(H))
    {
        printf("Priority queue is full");
        return;
    }
    for (i = ++H->Size; x < H->Elements[i/2]; i = i / 2)
    {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->Elements[i] = x;
}

int DeleteMin(PriorityQueue H)
{
    if (IsEmpty(H)){
        return -1;
    }
    int i, child;
    int minElement = H->Elements[1];
    int lastElement = H->Elements[H->Size];
    H->Size--;
    for(i=1; i*2 <= H->Size; i=child){
        child = i*2;
        if (child !=H->Size && H->Elements[child] > H->Elements[child + 1]){
            child++;
        }
        if (lastElement > H->Elements[child]){
            H->Elements[i] = H->Elements[child];
        } else {
            break;
        }
    }
    H->Elements[i] = lastElement;
    return minElement;
}

int FindMin(PriorityQueue H)
{
    if (IsEmpty(H)){
        return -1;
    }
    return H->Elements[1];
}

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0? 1: 0;
}

int IsFull(PriorityQueue H)
{
    return H->Capacity == H->Size ? 1 : 0;
}

int main(int argc, char const *argv[])
{
    PriorityQueue h = Initialize(15);
    Insert(10, h);
    Insert(8, h);
    Insert(13, h);
    printf("min is %d\n", FindMin(h));
    DeleteMin(h);
    printf("min is %d\n", FindMin(h));
    Destroy(h);
    return 0;
}
