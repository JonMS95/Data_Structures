#ifndef DOUBLY_LINKED_NODE
#define DOUBLY_LINKED_NODE

#include <iostream>

class DoublyLinkedNode
{
private:
    int data;
    DoublyLinkedNode* next;
    DoublyLinkedNode* prev;
public:
    DoublyLinkedNode();
    DoublyLinkedNode(int data, DoublyLinkedNode* next, DoublyLinkedNode* prev);
    ~DoublyLinkedNode();
    int GetData();
    void SetData(int data);
    DoublyLinkedNode* GetNextNode();
    DoublyLinkedNode* GetPrevNode();
    DoublyLinkedNode* SetNextNode(DoublyLinkedNode* next);
    DoublyLinkedNode* SetPrevNode(DoublyLinkedNode* prev);
};

#endif