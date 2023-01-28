#include "LevelOrderBinaryTree.hpp"

LevelOrderBinaryTree::LevelOrderBinaryTree()
{
    this->root = std::make_shared<BinaryTreeNode>();
}

LevelOrderBinaryTree::LevelOrderBinaryTree(int data)
{
    this->root = std::make_shared<BinaryTreeNode>(data);
}

LevelOrderBinaryTree::~LevelOrderBinaryTree(){}


/// @brief Insert node in level order.
/// @param data Value of the node that's meant to be set.
void LevelOrderBinaryTree::LevelOrderInsert(int data)
{
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    
    if(this->root == nullptr)
    {
        return;
    }
    
    q.push(this->GetRootValue());

    while(true)
    {
        if(q.front()->GetLeftNode() == nullptr)
        {
            q.front()->SetLeftNode(std::make_shared<BinaryTreeNode>(data));
            return;
        }
        if(q.front()->GetRightNode() == nullptr)
        {
            q.front()->SetRightNode(std::make_shared<BinaryTreeNode>(data));
            return;
        }
        q.push(q.front()->GetLeftNode());
        q.push(q.front()->GetRightNode());
        q.pop();
    }
}