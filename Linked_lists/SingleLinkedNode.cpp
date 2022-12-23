#include <cstddef>
#include <iostream>
#include "SingleLinkedNode.h"

SingleLinkedNode::SingleLinkedNode()
{
    this->data = 0;
    this->next = NULL;
}

SingleLinkedNode::SingleLinkedNode(int data)
{
    this->data = data;
    this->next = NULL;
}

SingleLinkedNode::~SingleLinkedNode()
{
    std::cout << "Removed node!\n";
}

void SingleLinkedNode::SetNextNode(SingleLinkedNode* next)
{
    this->next = next;
}

void SingleLinkedNode::SetData(int data)
{
    this->data = data;
}

SingleLinkedNode* SingleLinkedNode::GetNextNode()
{
    return this->next;
}

int SingleLinkedNode::GetData()
{
    return this->data;
}