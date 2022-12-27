#include "BinaryTreeNode.hpp"
#include <iostream>

BinaryTreeNode::BinaryTreeNode()
{
    this->data  = 0;
    this->left  = nullptr;
    this->right = nullptr;
    std::cout << "Created node with null values!\r\n";
}

BinaryTreeNode::BinaryTreeNode(int data, BinaryTreeNode* left, BinaryTreeNode* right)
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

void BinaryTreeNode::SetData(int data)
{
    this->data = data;
}

void BinaryTreeNode::SetLeftNode(BinaryTreeNode* left)
{
    this->left = left;
}

void BinaryTreeNode::SetRightNode(BinaryTreeNode* right)
{
    this->right = right;
}

int BinaryTreeNode::GetData()
{
    return this->data;
}

BinaryTreeNode* BinaryTreeNode::GetLeftNode()
{
    return this->left;
}

BinaryTreeNode* BinaryTreeNode::GetRightNode()
{
    return this->right;
}