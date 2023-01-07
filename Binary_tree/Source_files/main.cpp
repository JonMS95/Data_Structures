#include "BinaryTreeNode.hpp"
#include <iostream>
#include <memory>
#include <queue>

void LevelOrderInsert(std::shared_ptr<BinaryTreeNode> node, int data)
{
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(node);

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

void TraverseLevelOrder(std::shared_ptr<BinaryTreeNode> node)
{
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(node);

    while(q.empty() == false)
    {
        std::cout << q.front()->GetData() << "\r\n";
        if(q.front()->GetLeftNode() != nullptr)
        {
            q.push(q.front()->GetLeftNode());
        }
        if(q.front()->GetRightNode() != nullptr)
        {
            q.push(q.front()->GetRightNode());
        }
        q.pop();
    }
}

// Root-Left-Right
void TraversePreOrder(std::shared_ptr<BinaryTreeNode> node)
{
    std::cout << node->GetData() << "\r\n";
    if(node->GetLeftNode() != nullptr)
    {
        TraversePreOrder(node->GetLeftNode());
    }
    
    if(node->GetRightNode() != nullptr)
    {
        TraversePreOrder(node->GetRightNode());
    }
}

// Left-Root-Right
void TraverseInOrder(std::shared_ptr<BinaryTreeNode> node)
{
    if(node->GetLeftNode() != nullptr)
    {
        TraverseInOrder(node->GetLeftNode());
    }

    std::cout << node->GetData() << "\r\n";

    if(node->GetRightNode() != nullptr)
    {
        TraverseInOrder(node->GetRightNode());
    }
}

// Left-Right-Root
void TraversePostOrder(std::shared_ptr<BinaryTreeNode> node)
{
    if(node->GetLeftNode() != nullptr)
    {
        TraversePostOrder(node->GetLeftNode());
    }

    if(node->GetRightNode() != nullptr)
    {
        TraversePostOrder(node->GetRightNode());
    }

    std::cout << node->GetData() << "\r\n";
}

int main()
{
    std::shared_ptr<BinaryTreeNode> node4 = std::make_shared<BinaryTreeNode>(4);
    std::shared_ptr<BinaryTreeNode> node3 = std::make_shared<BinaryTreeNode>(3);
    std::shared_ptr<BinaryTreeNode> node2 = std::make_shared<BinaryTreeNode>(2, node4, nullptr);
    std::shared_ptr<BinaryTreeNode> node1 = std::make_shared<BinaryTreeNode>(1, node2, node3);

    std::shared_ptr<BinaryTreeNode> node5 = std::make_shared<BinaryTreeNode>(5);
    node2->SetRightNode(node5);

    std::shared_ptr<BinaryTreeNode> root = node1;

    LevelOrderInsert(node1, 6);

    std::cout << "**********************\r\n";
    std::cout << "Level Order\r\n";
    std::cout << "**********************\r\n";

    TraverseLevelOrder(node1);

    std::cout << "**********************\r\n";
    std::cout << "Pre Order\r\n";
    std::cout << "**********************\r\n";

    TraversePreOrder(node1);

    std::cout << "**********************\r\n";
    std::cout << "In Order\r\n";
    std::cout << "**********************\r\n";

    TraverseInOrder(node1);

    std::cout << "**********************\r\n";
    std::cout << "Post Order\r\n";
    std::cout << "**********************\r\n";

    TraversePostOrder(node1);

    return 0;
}