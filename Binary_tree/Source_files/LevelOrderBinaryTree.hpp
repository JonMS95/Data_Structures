#include "BinaryTree.hpp"

class LevelOrderBinaryTree : public BinaryTree
{
public:
    LevelOrderBinaryTree();
    LevelOrderBinaryTree(int data);
    ~LevelOrderBinaryTree();
    void LevelOrderInsert(int data);
};