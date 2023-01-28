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

/// @brief BT root value setter.
/// @param data Target value for the BT root.
void BinaryTree::SetRootValue(int data)
{
    this->root->SetData(data);
}

/// @brief Get root of the BT.
/// @return Pointer to BT root.
std::shared_ptr<BinaryTreeNode> BinaryTree::GetBTRoot()
{
    return this->root;
}

/// @brief Traverse BT in level order.
/// @param function Some generic function pointer.
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

/// @brief Check whether if the BT is complete or not.
/// @return True if the BT is complete, false otherwise.
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

/// @brief Get the depth of the BT.
/// @param node Node to start with (usually, the root node of the BT).
/// @param depth Maximum depth of the current function call.
/// @param currentCounter Current depth counter.
/// @return Depth of the BT.
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

/// @brief GetDepth method wrapper.
/// @return Depth of the BT.
int BinaryTree::GetBTDepth()
{
    return this->GetDepth(this->root, 0, 0);
}

/// @brief Function that prints the data within a BT node.
/// @param node Node which data is meant to be printed.
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

/// @brief Generic recursive traversal function for BT.
/// @param node Node to start with (usually, BT root node).
/// @param preOrderFn Generic function to be called in pre-order approach.
/// @param inOrderFn Generic function to be called in in-order approach.
/// @param postOrderFn Generic function to be called in post-order approach.
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

/// @brief Prints the data within every node in the BT in Level Order.
void BinaryTree::PrintLevelOrder()
{
    this->TraverseLevelOrder(this->printNodeData);
}

/// @brief Prints the data within every node in the BT in Pre-Order approach.
void BinaryTree::PrintPreOrder()
{
    this->BTRecursiveTraversal(this->root, this->printNodeData, nullptr, nullptr);
}

/// @brief Prints the data within every node in the BT in In-Order approach.
void BinaryTree::PrintInOrder()
{
    this->BTRecursiveTraversal(this->root, nullptr, this->printNodeData, nullptr);
}

/// @brief Prints the data within every node in the BT in Post-Order approach.
void BinaryTree::PrintPostOrder()
{
    this->BTRecursiveTraversal(this->root, nullptr, nullptr, this->printNodeData);
}
