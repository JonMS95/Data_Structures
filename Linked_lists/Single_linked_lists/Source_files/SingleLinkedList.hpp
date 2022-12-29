#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include "SingleLinkedNode.hpp"
#include <cstddef>
#include <memory>

class SingleLinkedlist {
    std::shared_ptr<SingleLinkedNode> head;

public:
    SingleLinkedlist();
    std::shared_ptr<SingleLinkedNode> GetHead();
    void InsertNode(int);
    void PrintList();
    void DeleteNode(int);
};

#endif