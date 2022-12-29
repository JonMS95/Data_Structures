#include "DoublyLinkedNode.hpp"

DoublyLinkedNode::DoublyLinkedNode()
{
    this->data = 0;
    this->next = nullptr;
    this->prev = nullptr;
    std::cout << "Created node!\r\n";
}

DoublyLinkedNode::DoublyLinkedNode( int data,
                                    std::shared_ptr<DoublyLinkedNode> prev,
                                    std::shared_ptr<DoublyLinkedNode> next)
{
    this->data = data;
    this->prev = prev;
    this->next = next;
    std::cout << "Created node!\r\n";
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

std::shared_ptr<DoublyLinkedNode> DoublyLinkedNode::GetNextNode()
{
    return this->next;
}

std::shared_ptr<DoublyLinkedNode> DoublyLinkedNode::GetPrevNode()
{
    return this->prev;
}

void DoublyLinkedNode::SetNextNode(std::shared_ptr<DoublyLinkedNode> next)
{
    this->next = next;
}

void DoublyLinkedNode::SetPrevNode(std::shared_ptr<DoublyLinkedNode> prev)
{
    this->prev = prev;
}