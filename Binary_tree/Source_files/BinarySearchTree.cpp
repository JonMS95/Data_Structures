#include "BinarySearchTree.hpp"

#define DATA_ALREADY_EXISTS         -1
#define NODE_SUCCESSFULLY_INSERTED  0

BinarySearchTree::BinarySearchTree(/* args */)
{
    this->root = std::make_shared<BinaryTreeNode>();
}

BinarySearchTree::BinarySearchTree(int data)
{
    this->root = std::make_shared<BinaryTreeNode>(data);
}

BinarySearchTree::~BinarySearchTree(){}

int BinarySearchTree::ProceduralBSTInsert(std::shared_ptr<BinaryTreeNode> node, int data)
{
    if(node == nullptr)
    {
        std::shared_ptr<BinaryTreeNode> newNode = std::make_shared<BinaryTreeNode>(data);
        return NODE_SUCCESSFULLY_INSERTED;
    }

    int currentNodeData = node->GetData();

    if(data < currentNodeData)
    {
        if (node->GetLeftNode() == nullptr)
        {
            node->SetLeftNode(std::make_shared<BinaryTreeNode>(data));
            return NODE_SUCCESSFULLY_INSERTED;
        }
        return ProceduralBSTInsert(node->GetLeftNode(), data);
    }
    else if(data > currentNodeData)
    {
        if (node->GetRightNode() == nullptr)
        {
            node->SetRightNode(std::make_shared<BinaryTreeNode>(data));
            return NODE_SUCCESSFULLY_INSERTED;
        }
        return ProceduralBSTInsert(node->GetRightNode(), data);
    }
    else
    {
        std::cout << "Data already found in a node of the BST.\r\n";
        return DATA_ALREADY_EXISTS;
    }
}

int BinarySearchTree::BSTInsert(int data)
{
    return ProceduralBSTInsert(this->root, data);
}