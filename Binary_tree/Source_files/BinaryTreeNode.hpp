#ifndef BINARY_TREE_NODE_HPP
#define BINARY_TREE_NODE_HPP

class BinaryTreeNode
{
private:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
public:
    BinaryTreeNode();
    BinaryTreeNode(int data);
    BinaryTreeNode(int data, BinaryTreeNode* left, BinaryTreeNode* right);
    ~BinaryTreeNode();
    void SetData(int data);
    void SetLeftNode(BinaryTreeNode* left);
    void SetRightNode(BinaryTreeNode* right);
    int GetData();
    BinaryTreeNode* GetLeftNode();
    BinaryTreeNode* GetRightNode();
};

#endif