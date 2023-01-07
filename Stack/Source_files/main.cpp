// Stack type in C++ is a container type, which allows us to organise some data in a LIFO queue fashion.
// Its header file should be included in order to use it.

// Some methods of the stack data structure are: empty, size, top, push, emplace pop and swap.
// Same as in vector built-in class, push does just place the element at the top of the stack, whereas
// emplace calls its constructor method.

#include <iostream>
#include <stack>

void printAndEmptyIntStack(std::stack<int> s)
{
    std::cout << "Initial stack size: " << s.size() << "\r\n";

    while(s.empty() == false)
    {
        std::cout << s.top() << "\r\n";
        s.pop();
    }
}

int main()
{
    std::stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    std::stack<int> s2;
    s2.push(5);
    s2.push(6);
    s2.push(7);
    s2.push(8);

    s1.swap(s2);

    printAndEmptyIntStack(s1);
    printAndEmptyIntStack(s2);

    return 0;
}