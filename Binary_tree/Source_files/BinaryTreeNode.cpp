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

void BinaryTreeNode::SetData(int data)
{
    this->data = data;
}

void BinaryTreeNode::SetLeftNode(std::shared_ptr<BinaryTreeNode> left)
{
    this->left = left;
}

void BinaryTreeNode::SetRightNode(std::shared_ptr<BinaryTreeNode> right)
{
    this->right = right;
}

int BinaryTreeNode::GetData()
{
    return this->data;
}

std::shared_ptr<BinaryTreeNode> BinaryTreeNode::GetLeftNode()
{
    return this->left;
}

std::shared_ptr<BinaryTreeNode> BinaryTreeNode::GetRightNode()
{
    return this->right;
}