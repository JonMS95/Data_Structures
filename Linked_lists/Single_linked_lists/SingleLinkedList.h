#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include "SingleLinkedNode.h"
#include <cstddef>

class SingleLinkedlist {
    SingleLinkedNode* head;

public:
    SingleLinkedlist();
    void insertNode(int);
    void printList();
    void deleteNode(int);
};

#endif