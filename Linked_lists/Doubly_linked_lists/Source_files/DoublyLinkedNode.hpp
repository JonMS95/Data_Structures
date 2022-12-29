#ifndef DOUBLY_LINKED_NODE
#define DOUBLY_LINKED_NODE

#include <iostream>
#include <memory>

class DoublyLinkedNode
{
private:
    int data;
    std::shared_ptr<DoublyLinkedNode> next;
    std::shared_ptr<DoublyLinkedNode> prev;
public:
    DoublyLinkedNode();
    DoublyLinkedNode(int data, std::shared_ptr<DoublyLinkedNode> next, std::shared_ptr<DoublyLinkedNode> prev);
    ~DoublyLinkedNode();
    int GetData();
    void SetData(int data);
    std::shared_ptr<DoublyLinkedNode> GetNextNode();
    std::shared_ptr<DoublyLinkedNode> GetPrevNode();
    void SetNextNode(std::shared_ptr<DoublyLinkedNode> next);
    void SetPrevNode(std::shared_ptr<DoublyLinkedNode> prev);
};

#endif