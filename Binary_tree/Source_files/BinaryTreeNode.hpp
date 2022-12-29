#ifndef BINARY_TREE_NODE_HPP
#define BINARY_TREE_NODE_HPP

#include <memory>

class BinaryTreeNode
{
private:
    int data;
    std::shared_ptr<BinaryTreeNode> left;
    std::shared_ptr<BinaryTreeNode> right;
public:
    BinaryTreeNode();
    BinaryTreeNode(int data);
    BinaryTreeNode(int data, std::shared_ptr<BinaryTreeNode> left, std::shared_ptr<BinaryTreeNode> right);
    ~BinaryTreeNode();
    void SetData(int data);
    void SetLeftNode(std::shared_ptr<BinaryTreeNode> left);
    void SetRightNode(std::shared_ptr<BinaryTreeNode> right);
    int GetData();
    std::shared_ptr<BinaryTreeNode> GetLeftNode();
    std::shared_ptr<BinaryTreeNode> GetRightNode();
};

#endif