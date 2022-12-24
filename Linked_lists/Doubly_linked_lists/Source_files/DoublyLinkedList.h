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
    void InsertFirstNode(int data);
    void InsertFinalNode(int data);
    void DeleteNode(int offset);
    void PrintList();
    int  GetListLength();
};

#endif