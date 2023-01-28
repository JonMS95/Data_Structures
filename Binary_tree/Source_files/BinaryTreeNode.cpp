#include "BinaryTreeNode.hpp"
#include <iostream>

BinaryTreeNode::BinaryTreeNode()
{
    this->data  = 0;
    this->left  = nullptr;
    this->right = nullptr;
    std::cout << "Created node with null values!\r\n";
}

BinaryTreeNode::BinaryTreeNode(int data)
{
    this->data  = data;
    std::cout << "Created node with:\r\n";
    std::cout << "\tData = " << data << "\r\n";
    std::cout << "\tLeft = nullptr\r\n";
    std::cout << "\tRight = nullptr\r\n";
}

BinaryTreeNode::BinaryTreeNode( int data,
                                std::shared_ptr<BinaryTreeNode> left,
                                std::shared_ptr<BinaryTreeNode> right)
{
    this->data  = data;
    this->left  = left;
    this->right = right;
    std::cout << "Created node with:\r\n";
    std::cout << "\tData = " << data << "\r\n";
    std::cout << "\tLeft = " << left << "\r\n";
    std::cout << "\tRight = " << right << "\r\n";
}

BinaryTreeNode::~BinaryTreeNode()
{
    std::cout << "Removed node!\r\n";
}

/// @brief Sets data value for the given node.
/// @param data value that's meant to be set.
void BinaryTreeNode::SetData(int data)
{
    this->data = data;
}

/// @brief Sets pointer to left child node.
/// @param left Pointer to the node that's going to be set as left child.
void BinaryTreeNode::SetLeftNode(std::shared_ptr<BinaryTreeNode> left)
{
    this->left = left;
}

/// @brief Sets pointer to right child node.
/// @param left Pointer to the node that's going to be set as right child.
void BinaryTreeNode::SetRightNode(std::shared_ptr<BinaryTreeNode> right)
{
    this->right = right;
}

/// @brief Gets the data stored in the current node.
/// @return Value of the data variable.
int BinaryTreeNode::GetData()
{
    return this->data;
}

/// @brief Left child node getter.
/// @return Pointer to the left child node.
std::shared_ptr<BinaryTreeNode> BinaryTreeNode::GetLeftNode()
{
    return this->left;
}

/// @brief Right child node getter.
/// @return Pointer to the right child node.
std::shared_ptr<BinaryTreeNode> BinaryTreeNode::GetRightNode()
{
    return this->right;
}