#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
#include "DoublyLinkedNode.h"

class DoublyLinkedList
{
private:
    DoublyLinkedNode* head;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void InsertNode(int data, int offset);
    void DeleteNode(int offset);
    void PrintList();
};

#endif