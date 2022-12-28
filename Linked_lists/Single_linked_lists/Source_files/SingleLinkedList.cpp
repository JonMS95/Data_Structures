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
void SingleLinkedlist::InsertNode(int data)
{
    std::shared_ptr<SingleLinkedNode> newNode = std::make_shared<SingleLinkedNode>(data);
    if(this->head == NULL)
    {
        this->head = newNode;
        return;
    }

    std::shared_ptr<SingleLinkedNode> temp = this->head;
    while(temp->GetNextNode() != NULL)
    {
        temp = temp->GetNextNode();
    }

    temp->SetNextNode(newNode);
}

void SingleLinkedlist::PrintList()
{
    //If the head of the list is null, then the list contains no element whatsoever.
    if(this->head == NULL)
    {
        std::cout << "List is empty!\n";
        return;
    }

    // Otherwise, print each nodes data, then point at the next node in the list by accessing the address to the next node.
    // Do this for each node in the list, until the next pointed element is NULL. Use a temporary SingleLinkedNode object.
    // If the head of the linked list is modified, then the list may be lost.
    std::shared_ptr<SingleLinkedNode> currentNode = this->head;

    while(currentNode != NULL)
    {
        std::cout << currentNode->GetData() << "\n";
        currentNode = currentNode->GetNextNode();
    }
}

void SingleLinkedlist::DeleteNode(int nodeOffset)
{
    int linkedListLength = 1;

    std::shared_ptr<SingleLinkedNode> currentNode   = this->head;
    std::shared_ptr<SingleLinkedNode> previousNode;

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

    if(nodeOffset == 0)
    {
        this->head = this->head->GetNextNode();
        return;
    }

    for(int i = 0; i < nodeOffset; i++)
    {
        previousNode = currentNode;
        currentNode = currentNode->GetNextNode();
    }

    previousNode->SetNextNode(currentNode->GetNextNode());

    // Instead of using new and delete, using shared pointers is worth it here. Once a node is not pointed by
    // any pointer, it vanishes. In this case, previous node points to the node that's one ahead the next node
    // so the node that's next to the previous one (currentNode) gets automatically deleted once the scope of
    // this function is exited.
}