#include "BinaryTree.hpp"

BinaryTree::BinaryTree()
{
    this->root = std::make_shared<BinaryTreeNode>();
    std::cout << "Created Null Binary Tree!\r\n";
}

BinaryTree::BinaryTree(int data)
{
    this->root = std::make_shared<BinaryTreeNode>(data);
    std::cout << "Created Binary Tree!\r\n";
}

BinaryTree::~BinaryTree(){}

std::shared_ptr<BinaryTreeNode> BinaryTree::GetRootValue()
{
    return this->root;
}

void BinaryTree::SetRootValue(int data)
{
    this->root->SetData(data);
}

std::shared_ptr<BinaryTreeNode> BinaryTree::GetBTRoot()
{
    return this->root;
}

void BinaryTree::TraverseLevelOrder(void(*function)(void*))
{
    if(this->root == nullptr)
    {
        return;
    }
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(this->root);

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

bool BinaryTree::IsBTComplete()
{
    std::vector<bool> nullityVector;
    bool previousValue = true;
    std::queue<std::shared_ptr<BinaryTreeNode>> q;

    if(this->root == nullptr)
    {
        return false;
    }

    q.push(this->root);
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

int BinaryTree::GetDepth(std::shared_ptr<BinaryTreeNode> node, int depth = 0, int currentCounter = 0)
{
    int dp = depth;
    int cc = currentCounter;

    if (node == nullptr)
    {
        return -1;
    }

    (cc)++;

    if(cc > dp)
    {
        dp = cc;
    }

    if (node->GetLeftNode() != nullptr)
    {
        dp = GetDepth(node->GetLeftNode(), dp, cc);
    }

    if (node->GetRightNode() != nullptr)
    {
        dp = GetDepth(node->GetRightNode(), dp, cc);
    }

    (cc)--;

    return dp;
}

int BinaryTree::GetBTDepth()
{
    return this->GetDepth(this->root, 0, 0);
}

void BinaryTree::printNodeData(void* node)
{
    BinaryTreeNode* castedNode = (BinaryTreeNode*) node;

    if(castedNode == nullptr)
    {
        std::cout << "Null node!\r\n";
        return;
    }

    std::cout << castedNode->GetData() << "\r\n";
}

void BinaryTree::BTRecursiveTraversal(std::shared_ptr<BinaryTreeNode> node,
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

void BinaryTree::PrintLevelOrder()
{
    this->TraverseLevelOrder(this->printNodeData);
}

void BinaryTree::PrintPreOrder()
{
    this->BTRecursiveTraversal(this->root, this->printNodeData, nullptr, nullptr);
}

void BinaryTree::PrintInOrder()
{
    this->BTRecursiveTraversal(this->root, nullptr, this->printNodeData, nullptr);
}

void BinaryTree::PrintPostOrder()
{
    this->BTRecursiveTraversal(this->root, nullptr, nullptr, this->printNodeData);
}
