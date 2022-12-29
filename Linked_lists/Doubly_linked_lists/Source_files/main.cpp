#include "DoublyLinkedList.hpp"

int main()
{
    DoublyLinkedList testList;
    testList.InsertFinalNode(0);
    testList.InsertFinalNode(1);
    testList.InsertFinalNode(2);
    testList.InsertFinalNode(4);

    testList.PrintList();

    testList.DeleteNode(2);

    testList.PrintList();

    testList.DeleteNode(0);

    testList.PrintList();

    testList.DeleteNode(0);

    testList.PrintList();

    testList.InsertFirstNode(7);

    testList.PrintList();

    testList.DeleteNode(0);

    testList.PrintList();

    testList.DeleteNode(0);

    testList.PrintList();

    return 0;
}