//
// Created by xudalei on 2021/4/2.
//
#include "tree.h"
#include <stdlib.h>

SearchTree MakeEmpty(SearchTree T){
    if (T != NULL){
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
}

