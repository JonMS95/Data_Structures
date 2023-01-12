#include "BinaryTreeNode.hpp"
#include <iostream>
#include <memory>
#include <queue>
#include <cstdlib>
#include <ctime>

#define DATA_ALREADY_EXISTS         -1
#define NODE_SUCCESSFULLY_INSERTED  0

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

int InsertBinarySearchTree(std::shared_ptr<BinaryTreeNode> node, int data)
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
        return InsertBinarySearchTree(node->GetLeftNode(), data);
    }
    else if(data > currentNodeData)
    {
        if (node->GetRightNode() == nullptr)
        {
            node->SetRightNode(std::make_shared<BinaryTreeNode>(data));
            return NODE_SUCCESSFULLY_INSERTED;
        }
        return InsertBinarySearchTree(node->GetRightNode(), data);
    }
    else
    {
        std::cout << "Data already found in a node of the BST.\r\n";
        return DATA_ALREADY_EXISTS;
    }
}

void TraverseLevelOrder(std::shared_ptr<BinaryTreeNode> node)
{
    if(node == nullptr)
    {
        return;
    }
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
    if(node == nullptr)
    {
        return;
    }

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
    if(node == nullptr)
    {
        return;
    }

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
    if(node == nullptr)
    {
        return;
    }

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

void getNullityVector(std::shared_ptr<BinaryTreeNode> node, std::vector<bool>& nullityVector)
{
    if(node == nullptr)
    {
        nullityVector.push_back(false);
        return;
    }
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(node);
    nullityVector.push_back(true);

    while(q.empty() == false)
    {
        std::cout << q.front()->GetData() << "\r\n";
        if(q.front()->GetLeftNode() != nullptr)
        {
            q.push(q.front()->GetLeftNode());
            nullityVector.push_back(true);
        }
        else
        {
            nullityVector.push_back(false);
        }
        if(q.front()->GetRightNode() != nullptr)
        {
            q.push(q.front()->GetRightNode());
            nullityVector.push_back(true);
        }
        else
        {
            nullityVector.push_back(false);
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

    std::cout << "**********************\r\n";
    std::cout << "Creating a BST now.\r\n";
    std::cout << "**********************\r\n";

    std::shared_ptr<BinaryTreeNode> BSTRootNode = std::make_shared<BinaryTreeNode>(50);

    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        int randomNumber_1_100 = rand()%100 + 1;
        InsertBinarySearchTree(BSTRootNode, randomNumber_1_100);
    }

    TraverseInOrder(BSTRootNode);

    std::vector<bool> nullityVector;
    getNullityVector(node1, nullityVector);

    for(long unsigned int i = 0; i < nullityVector.size(); i++)
    {
        std::cout << nullityVector[i] << " ";
    }

    bool nullFound = false;

    for(long unsigned int i = 0; i < nullityVector.size(); i++)
    {
        if(nullityVector[i] == false)
        {
            if(nullFound == true);
        }
        else
        {
            if(nullFound == true)
            {
                std::cout << "Incomplete Tree!";
            }
        }
    }

    std::cout << "\r\n";

    return 0;
}