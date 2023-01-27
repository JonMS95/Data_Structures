#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ProceduralBT.hpp"
#include "LevelOrderBinaryTree.hpp"
#include "BinarySearchTree.hpp"

int main()
{
    BinarySearchTree BT(50);

    srand(time(NULL));
    for(int i = 0; i < 7; i++)
    {
        int randomNumber_1_100 = rand()%100 + 1;
        BT.BSTInsert(randomNumber_1_100);
    }

    std::cout << "Level Order\r\n*************\r\n";

    BT.PrintLevelOrder();

    std::cout << "Pre Order\r\n*************\r\n";

    BT.PrintPreOrder();

    std::cout << "In Order\r\n*************\r\n";

    BT.PrintInOrder();

    std::cout << "Post Order\r\n*************\r\n";

    BT.PrintPostOrder();

    std::cout << "Is tree complete? " << BT.IsBTComplete() << "\r\n";

    return 0;
}