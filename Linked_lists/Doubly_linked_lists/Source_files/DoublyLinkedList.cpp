#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
    this->head = nullptr;
}

DoublyLinkedList::~DoublyLinkedList(){}

void DoublyLinkedList::InsertNode(int data, int offset)
{

}

void DoublyLinkedList::DeleteNode(int offset)
{

}

void DoublyLinkedList::PrintList()
{
    DoublyLinkedNode* currentNode = this->head;
    
    while(currentNode->GetNextNode() != nullptr)
    {
        std::cout << currentNode->GetData() << "\n";
    }
}