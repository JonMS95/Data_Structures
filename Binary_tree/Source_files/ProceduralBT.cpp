#include "ProceduralBT.hpp"

/// @brief Inserts the given node into the tree in level order.
/// @param node The node to start with (usually, the LOBT root).
/// @param data The data value that's meamt to be inserted.
void LevelOrderInsert(std::shared_ptr<BinaryTreeNode> node, int data)
{
    std::queue<std::shared_ptr<BinaryTreeNode>> q;

    if(node == nullptr)
    {
        return;
    }

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

/// @brief Insert a node in a BST.
/// @param node The node to start with (usually, the root of the BST).
/// @param data The data value of the node that's wanted to be inserted.
/// @return 0 if the node was successfully inserted, -1 if the data already exists within the BST.
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

/// @brief Traverse BT in level order.
/// @param node The node to start with.
/// @param function A generic function pointer.
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

/// @brief Tells whether if the current tree is complete or not.
/// @param node The node to start with.
/// @return True if the tree is complete, false otherwise.
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

/// @brief 
/// @param node 
/// @param depth 
/// @param currentCounter 
/// @return 
int GetBTDepth(std::shared_ptr<BinaryTreeNode> node, int depth = 0, int currentCounter = 0)
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