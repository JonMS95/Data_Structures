#include "BinaryTreeNode.hpp"

int main()
{
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node2 = new BinaryTreeNode(2, node4, nullptr);
    BinaryTreeNode* node1 = new BinaryTreeNode(1, node2, node3);

    return 0;
}