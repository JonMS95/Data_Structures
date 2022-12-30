// Same as an array, a linked list are linear data structures, but elements are not located next to each other. Instead, they are located at arbitrarily
// set memory indexes. Thus, information is stored in nodes, which include some information, as well as the memory index where the next node is located.
// The motivation to use linked lists instead of arrays comes mainly from wanting to be able to modify the information set without having to reallocate
// the whole data structure.
// On the other hand, random access is not allowed. Apart from that, extra memory is required in each element of the structure, just to have enough
// space to store the pointer to the next node.
// The first element in a linked list is also known as "head".
#include <iostream>
#include "SingleLinkedList.hpp"

int main()
{
    SingleLinkedlist testList;

    testList.InsertNode(0);
    testList.InsertNode(1);
    testList.InsertNode(2);
    testList.InsertNode(4);
    testList.InsertNode(8);

    testList.PrintList();

    testList.DeleteNode(2);

    testList.PrintList();

    testList.DeleteNode(0);

    testList.PrintList();

    testList.DeleteNode(2);

    testList.PrintList();

    testList.DeleteNode(0);

    testList.PrintList();

    testList.DeleteNode(0);

    testList.PrintList();

    return 0;
}