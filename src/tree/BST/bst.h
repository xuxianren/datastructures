//
// Created by xudalei on 2021/4/2.
//

#ifndef DATASTRUCTURES_TREE_H
#define DATASTRUCTURES_TREE_H
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);


struct TreeNode
{
    int Element;
    SearchTree Left;
    SearchTree Right;
};


#endif //DATASTRUCTURES_TREE_H
