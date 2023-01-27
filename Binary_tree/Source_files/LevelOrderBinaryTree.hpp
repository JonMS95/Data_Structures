#ifndef LEVEL_ORDER_BINARY_TREE_HPP
#define LEVEL_ORDER_BINARY_TREE_HPP

#include "BinaryTree.hpp"

class LevelOrderBinaryTree : public BinaryTree
{
public:
    LevelOrderBinaryTree();
    LevelOrderBinaryTree(int data);
    ~LevelOrderBinaryTree();
    void LevelOrderInsert(int data);
};

#endif