#include "SingleLinkedList.h"
#include <iostream>

SingleLinkedlist::SingleLinkedlist()
{
    this->head = NULL;
}

// To insert a new node, first check if the head (i.e., the first element of the linked list) is null or not. If so, then place
// the newly created node at this position. Note that linked lists are usually implemented in heap memory (as it's being done in
// this case). Therefore, "new" keyword hast to be used in roder to allocate those nodes somewhere in memory, and not to be
// removed by the destructor method of the SingleLinkedNode class each time the scope of the function below is exited.
void SingleLinkedlist::insertNode(int data)
{
    SingleLinkedNode* newNode = new SingleLinkedNode(data);

    if(this->head == NULL)
    {
        this->head = newNode;
        return;
    }

    SingleLinkedNode* temp = this->head;
    while(temp->GetNextNode() != NULL)
    {
        temp = temp->GetNextNode();
    }

    temp->SetNextNode(newNode);
}

void SingleLinkedlist::printList()
{
    //If the head of the list is null, then the list contains no element whatsoever.
    if(this->head == NULL)
    {
        std::cout <<"List is empty!\n";
        return;
    }

    // Otherwise, print each nodes data, then point at the next node in the list by accessing the address to the next node.
    // Do this for each node in the list, until the next pointed element is NULL. Use a temporary SingleLinkedNode object.
    // If the head of the linked list is modified, then the list may be lost.
    SingleLinkedNode* currentNode = this->head;

    while(currentNode != NULL)
    {
        std::cout << currentNode->GetData() << "\n";
        currentNode = currentNode->GetNextNode();
    }
}

void SingleLinkedlist::deleteNode(int nodeOffset)
{
    int linkedListLength = 1;

    SingleLinkedNode* currentNode   = this->head;
    SingleLinkedNode* previousNode;

    if(this->head == NULL)
    {
        std::cout << "Empty list!\n";
        return;
    }

    while(currentNode->GetNextNode() != NULL)
    {
        linkedListLength++;
        currentNode = currentNode->GetNextNode();
    }

    if(nodeOffset >= linkedListLength)
    {
        std::cout << "Offset is out of boundaries!\n";
        return;
    }

    currentNode   = this->head;

    for(int i = 0; i < nodeOffset; i++)
    {
        previousNode = currentNode;
        currentNode = currentNode->GetNextNode();
    }

    previousNode->SetNextNode(currentNode->GetNextNode());
    delete currentNode;
}