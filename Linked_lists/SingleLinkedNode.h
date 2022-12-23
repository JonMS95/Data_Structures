class SingleLinkedNode
{
    private:
        int data;
        SingleLinkedNode* next;
    public:
        SingleLinkedNode();
        SingleLinkedNode(int data);
        ~SingleLinkedNode();
        void SetNextNode(SingleLinkedNode* next);
        void SetData(int data);
        SingleLinkedNode* GetNextNode();
        int GetData();
};