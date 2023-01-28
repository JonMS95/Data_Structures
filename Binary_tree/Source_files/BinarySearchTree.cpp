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

/// @brief A procedural BST insert implementation. This static method will remain as private.
/// @param node The node to start with (usually, the root of the BST).
/// @param data The data value that's emant to be inserted.
/// @return 0 if the node was successfully inserted, -1 if the data already exists.
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

/// @brief Inserts a node in the BST.
/// @param data The data value that's wanted to be inserted within the BST.
/// @return 0 if the node was successfully inserted, -1 if the data already exists.
int BinarySearchTree::BSTInsert(int data)
{
    return ProceduralBSTInsert(this->root, data);
}