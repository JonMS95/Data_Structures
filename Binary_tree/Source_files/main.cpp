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

void TraverseLevelOrder(std::shared_ptr<BinaryTreeNode> node,
                        void(*function)(void*))
{
    if(node == nullptr)
    {
        return;
    }
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(node);

    while(q.empty() == false)
    {
        if(function != nullptr)
        {
            function(q.front().get());
        }
        
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

bool IsBTComplete(std::shared_ptr<BinaryTreeNode> node)
{
    std::vector<bool> nullityVector;
    bool previousValue = true;
    std::queue<std::shared_ptr<BinaryTreeNode>> q;

    if(node == nullptr)
    {
        return false;
    }

    q.push(node);
    nullityVector.push_back(true);

    while(q.empty() == false)
    {
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

    for(long unsigned int i = 0; i < nullityVector.size(); i++)
    {
        if((previousValue == false) && (nullityVector[i] == true))
        {
            return false;
        }
        previousValue = nullityVector[i];
    }

    return true;
}

void printNodeData(void* node)
{
    BinaryTreeNode* castedNode = (BinaryTreeNode*) node;

    if(castedNode == nullptr)
    {
        std::cout << "Null node!\r\n";
        return;
    }

    std::cout << castedNode->GetData() << "\r\n";
}

int GetBTDepth(std::shared_ptr<BinaryTreeNode> node, int depth = 0, int currentCounter = 0)
{
    int dp = depth;
    int cc = currentCounter;

    if (node == nullptr)
    {
        return -1;
    }

    (cc)++;

    if(cc >  dp)
    {
        dp = cc;
    }

    if (node->GetLeftNode() != nullptr)
    {
        dp = GetBTDepth(node->GetLeftNode(), dp, cc);
    }

    if (node->GetRightNode() != nullptr)
    {
        dp = GetBTDepth(node->GetRightNode(), dp, cc);
    }

    (cc)--;

    return dp;
}

/// @brief Generic recursive function that behaves in pre, in or post order mode
/// depending on the input parameter functions that are passed to it.
/// @param node Current BT node
/// @param preOrderFn Pre-order task
/// @param inOrderFn In-order task
/// @param postOrderFn Post-order task
void BTRecursiveTraversal(std::shared_ptr<BinaryTreeNode> node,
                         void (*preOrderFn)(void*),
                         void (*inOrderFn)(void*),
                         void (*postOrderFn)(void*)
                        )
{
    if(node == nullptr)
    {
        return;
    }

    if(preOrderFn != nullptr)
    {
        preOrderFn(node.get());
    }

    if(node->GetLeftNode() != nullptr)
    {
        BTRecursiveTraversal(node->GetLeftNode(), preOrderFn, inOrderFn, postOrderFn);
    }

    if(inOrderFn != nullptr)
    {
        inOrderFn(node.get());
    }

    if(node->GetRightNode() != nullptr)
    {
        BTRecursiveTraversal(node->GetRightNode(), preOrderFn, inOrderFn, postOrderFn);
    }

    if(postOrderFn != nullptr)
    {
        postOrderFn(node.get());
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

    std::shared_ptr<BinaryTreeNode> node7 = std::make_shared<BinaryTreeNode>(7);

    node3->GetLeftNode()->SetRightNode(node7);

    std::cout << "**********************\r\n";
    std::cout << "Level Order\r\n";
    std::cout << "**********************\r\n";

    TraverseLevelOrder(node1, printNodeData);

    std::cout << "**********************\r\n";
    std::cout << "Pre Order\r\n";
    std::cout << "**********************\r\n";

    BTRecursiveTraversal(node1, printNodeData, nullptr, nullptr);

    std::cout << "**********************\r\n";
    std::cout << "In Order\r\n";
    std::cout << "**********************\r\n";

    BTRecursiveTraversal(node1, nullptr, printNodeData, nullptr);

    std::cout << "**********************\r\n";
    std::cout << "Post Order\r\n";
    std::cout << "**********************\r\n";

    BTRecursiveTraversal(node1, nullptr, nullptr, printNodeData);

    std::cout << "Tree depth: " << GetBTDepth(node1) << "\r\n";

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

    BTRecursiveTraversal(BSTRootNode, nullptr, printNodeData, nullptr);

    std::cout << "Is tree complete? " << IsBTComplete(node1) << "\r\n";

    std::cout << "\r\n";

    return 0;
}