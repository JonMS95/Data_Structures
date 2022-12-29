#ifndef SINGLE_LINKED_NODE
#define SINGLE_LINKED_NODE

#include <memory>

class SingleLinkedNode
{
    private:
        int data;
        std::shared_ptr<SingleLinkedNode> next;
    public:
        SingleLinkedNode();
        SingleLinkedNode(int data);
        ~SingleLinkedNode();
        void SetNextNode(std::shared_ptr<SingleLinkedNode> next);
        void SetData(int data);
        std::shared_ptr<SingleLinkedNode> GetNextNode();
        int GetData();
};

#endif