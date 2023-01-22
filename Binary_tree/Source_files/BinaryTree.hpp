#include "BinaryTreeNode.hpp"
#include <iostream>
#include <queue>

class BinaryTree
{
private:
    std::shared_ptr<BinaryTreeNode> root;
    void TraverseLevelOrder(void(*function)(void*));
    int GetDepth(std::shared_ptr<BinaryTreeNode> node, int depth, int currentCounter);
    static void printNodeData(void* node);
    void BTRecursiveTraversal(std::shared_ptr<BinaryTreeNode> node,
                        void (*preOrderFn)(void*),
                        void (*inOrderFn)(void*),
                        void (*postOrderFn)(void*));
public:
    BinaryTree(int data);
    ~BinaryTree();
    std::shared_ptr<BinaryTreeNode> GetBTRoot();
    bool IsBTComplete();
    int GetBTDepth();
    void PrintLevelOrder();
    void PrintPreOrder();
    void PrintInOrder();
    void PrintPostOrder();
    void LevelOrderInsert(int data);
};