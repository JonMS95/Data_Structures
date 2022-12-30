#include "DoublyLinkedNode.hpp"

DoublyLinkedNode::DoublyLinkedNode(): data(0), next(nullptr), prev(nullptr)
{
    std::cout << "Created node!\r\n";
}

DoublyLinkedNode::DoublyLinkedNode( int data,
                                    std::shared_ptr<DoublyLinkedNode> prev,
                                    std::shared_ptr<DoublyLinkedNode> next)
                                    :data(0)
{
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