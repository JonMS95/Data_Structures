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
    DoublyLinkedNode* GetNextNode();
    DoublyLinkedNode* GetPrevNode();
    DoublyLinkedNode* SetNextNode(DoublyLinkedNode* next);
    DoublyLinkedNode* SetPrevNode(DoublyLinkedNode* prev);
};