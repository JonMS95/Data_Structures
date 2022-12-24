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
    DoublyLinkedNode* newNode = new DoublyLinkedNode(data, nullptr, nullptr);

    // If list is currently empty:
    if(this->head == nullptr)
    {
        this->head = newNode;
        return;
    }

    DoublyLinkedNode* currentNode = this->head;

    while(currentNode->GetNextNode() != nullptr)
    {
        currentNode = currentNode->GetNextNode();
    }

    newNode->SetPrevNode(currentNode);
    newNode->GetPrevNode()->SetNextNode(newNode);

    // DoublyLinkedNode* newNode = new DoublyLinkedNode(data, currentNode, nullptr);
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

    if(offset == 0)
    {
        this->head = this->head->GetNextNode();
        delete currentNode;
        return;
    }

    for(int i = 0; i < offset; i++)
    {
        currentNode = currentNode->GetNextNode();
    }

    currentNode->GetPrevNode()->SetNextNode(currentNode->GetNextNode());
    currentNode->GetNextNode()->SetPrevNode(currentNode->GetPrevNode());
    delete currentNode;
}

void DoublyLinkedList::PrintList()
{
    DoublyLinkedNode* currentNode = this->head;
    
    if(this->head == nullptr)
    {
        std::cout << "List is empty!\n";
    }

    while(currentNode != nullptr)
    {
        std::cout << currentNode->GetData() << "\n";
        currentNode = currentNode->GetNextNode();
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