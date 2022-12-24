#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
    this->head = nullptr;
}

DoublyLinkedList::~DoublyLinkedList(){}

void DoublyLinkedList::InsertFirstNode(int data)
{
    if(this->head == nullptr)
    {
        this->head = new DoublyLinkedNode(data, nullptr, nullptr);
        return;
    }

    // Set first node's previous node as the one that's meant to be inserted.
    DoublyLinkedNode* newNode = new DoublyLinkedNode(data, nullptr, this->head);
    this->head->SetPrevNode(newNode);
    this->head = newNode;
}

void DoublyLinkedList::InsertFinalNode(int data)
{
    DoublyLinkedNode* currentNode = this->head;

    while(currentNode->GetNextNode() != nullptr)
    {
        currentNode = currentNode->GetNextNode();
    }

    DoublyLinkedNode* newNode = new DoublyLinkedNode(data, currentNode, nullptr);
}

void DoublyLinkedList::DeleteNode(int offset)
{
    int listLength = this->GetListLength();
    DoublyLinkedNode* currentNode = this->head;

    if(listLength == 0)
    {
        std::cout << "Empty list!\n";
        return;
    }

    if(offset >= listLength)
    {
        std::cout << "Offset is out of boundaries!\n";
        return;
    }

    for(int i = 0; i < offset; i++)
    {
        currentNode = currentNode->GetNextNode();
    }

    currentNode->GetPrevNode()->SetNextNode(currentNode->GetNextNode());
    currentNode->GetNextNode()->SetPrevNode(currentNode->GetPrevNode());
}

void DoublyLinkedList::PrintList()
{
    DoublyLinkedNode* currentNode = this->head;
    
    while(currentNode->GetNextNode() != nullptr)
    {
        std::cout << currentNode->GetData() << "\n";
    }
}

int DoublyLinkedList::GetListLength()
{
    int counter = 1;
    DoublyLinkedNode* currentNode = this->head;
    
    if(this->head == nullptr)
    {
        return 0;
    }

    while(currentNode->GetNextNode() != nullptr)
    {
        counter++;
        currentNode = currentNode->GetNextNode();
    }

    return counter;
}