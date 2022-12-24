#include "DoublyLinkedNode.h"

DoublyLinkedNode::DoublyLinkedNode()
{
    this->data = 0;
    this->next = nullptr;
    this->prev = nullptr;
}

DoublyLinkedNode::DoublyLinkedNode(int data, DoublyLinkedNode* next, DoublyLinkedNode* prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

DoublyLinkedNode::~DoublyLinkedNode()
{
    std::cout << "Removed node!\n";
}

DoublyLinkedNode* DoublyLinkedNode::GetNextNode()
{
    return this->next;
}

DoublyLinkedNode* DoublyLinkedNode::GetPrevNode()
{
    return this->prev;
}

DoublyLinkedNode* DoublyLinkedNode::SetNextNode(DoublyLinkedNode* next)
{
    this->next = next;
}

DoublyLinkedNode* DoublyLinkedNode::SetPrevNode(DoublyLinkedNode* prev)
{
    this->prev = prev;
}