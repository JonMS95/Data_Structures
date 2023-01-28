#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include "BinaryTreeNode.hpp"
#include <iostream>
#include <queue>

class BinaryTree
{
private:
    void TraverseLevelOrder(void(*function)(void*));
    int GetDepth(std::shared_ptr<BinaryTreeNode> node, int depth, int currentCounter);
    static void printNodeData(void* node);
    void BTRecursiveTraversal(std::shared_ptr<BinaryTreeNode> node,
                        void (*preOrderFn)(void*),
                        void (*inOrderFn)(void*),
                        void (*postOrderFn)(void*));

protected:
    std::shared_ptr<BinaryTreeNode> root;

public:
    BinaryTree();
    BinaryTree(int data);
    ~BinaryTree();
    void SetRootValue(int data);
    std::shared_ptr<BinaryTreeNode> GetBTRoot();
    bool IsBTComplete();
    int GetBTDepth();
    void PrintLevelOrder();
    void PrintPreOrder();
    void PrintInOrder();
    void PrintPostOrder();
    std::vector<int> VectorBT();
};

#endif