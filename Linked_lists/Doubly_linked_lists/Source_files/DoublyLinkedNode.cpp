#include "DoublyLinkedNode.h"

DoublyLinkedNode::DoublyLinkedNode()
{
    this->data = 0;
    this->next = nullptr;
    this->prev = nullptr;
}

DoublyLinkedNode::DoublyLinkedNode(int data, DoublyLinkedNode* prev, DoublyLinkedNode* next)
{
    this->data = data;
    this->prev = prev;
    this->next = next;
}

DoublyLinkedNode::~DoublyLinkedNode()
{
    std::cout << "Removed node!\n";
}

int DoublyLinkedNode::GetData()
{
    return this->data;
}

void DoublyLinkedNode::SetData(int data)
{
    this->data = data;
}

DoublyLinkedNode* DoublyLinkedNode::GetNextNode()
{
    return this->next;
}

DoublyLinkedNode* DoublyLinkedNode::GetPrevNode()
{
    return this->prev;
}

void DoublyLinkedNode::SetNextNode(DoublyLinkedNode* next)
{
    this->next = next;
}

void DoublyLinkedNode::SetPrevNode(DoublyLinkedNode* prev)
{
    this->prev = prev;
}