#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP


#include "BinaryTree.hpp"

#define DATA_ALREADY_EXISTS         -1
#define NODE_SUCCESSFULLY_INSERTED  0

class BinarySearchTree : public BinaryTree
{
private:
    static int ProceduralBSTInsert(std::shared_ptr<BinaryTreeNode> node, int data);
public:
    BinarySearchTree();
    BinarySearchTree(int data);
    ~BinarySearchTree();
    int BSTInsert(int data);
};

#endif