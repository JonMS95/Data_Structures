#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList testList;
    testList.InsertFinalNode(0);
    testList.InsertFinalNode(1);
    testList.InsertFinalNode(2);
    testList.InsertFinalNode(4);

    testList.PrintList();

    return 0;
}