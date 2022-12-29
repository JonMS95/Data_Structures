#include <cstddef>
#include <iostream>
#include "SingleLinkedNode.hpp"

SingleLinkedNode::SingleLinkedNode()
{
    this->data = 0;
    this->next = NULL;
    std::cout << "Created node!\r\n";
}

SingleLinkedNode::SingleLinkedNode(int data)
{
    this->data = data;
    this->next = NULL;
    std::cout << "Created node!\r\n";
}

SingleLinkedNode::~SingleLinkedNode()
{
    std::cout << "Removed node!\n";
}

void SingleLinkedNode::SetNextNode(std::shared_ptr<SingleLinkedNode> next)
{
    this->next = next;
}

void SingleLinkedNode::SetData(int data)
{
    this->data = data;
}

std::shared_ptr<SingleLinkedNode> SingleLinkedNode::GetNextNode()
{
    return this->next;
}

int SingleLinkedNode::GetData()
{
    return this->data;
}