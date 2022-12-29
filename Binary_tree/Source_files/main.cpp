#include "BinaryTreeNode.hpp"
#include <iostream>
#include <memory>
#include <queue>

void InsertNodeLevelOrder(std::shared_ptr<BinaryTreeNode> node, int data)
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

void printNodesByLevel(std::shared_ptr<BinaryTreeNode> node)
{
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(node);

    while(q.empty() == false)
    {
        std::cout << "Data:\t" << q.front()->GetData() << "\r\n";
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

int main()
{
    std::shared_ptr<BinaryTreeNode> node4 = std::make_shared<BinaryTreeNode>(4);
    std::shared_ptr<BinaryTreeNode> node3 = std::make_shared<BinaryTreeNode>(3);
    std::shared_ptr<BinaryTreeNode> node2 = std::make_shared<BinaryTreeNode>(2, node4, nullptr);
    std::shared_ptr<BinaryTreeNode> node1 = std::make_shared<BinaryTreeNode>(1, node2, node3);

    std::shared_ptr<BinaryTreeNode> node5 = std::make_shared<BinaryTreeNode>(5);
    node2->SetRightNode(node5);

    InsertNodeLevelOrder(node1, 6);

    printNodesByLevel(node1);

    return 0;
}