#include <iostream>
#include <queue>

// In order to perform operations with buit-in queue data type, queue header file should be included.
// Some methods of the queue class: empty, size, emplace, front, back, push(g), pop. Keep in mind that it is
// a FIFO queue (Last In, First Out).
// Same as with vectors, push inserts the element, whereas emplace calls the constructor, then inserts it in 
// the queue.

void printAndEmptyIntQueue(std::queue<int> q)
{
    std::cout << "Initial queue size: " << q.size() << "\r\n";
    std::cout << "First element: " << q.front() << "\r\n";
    std::cout << "Last element: " << q.back() << "\r\n";
    while(q.empty() == false)
    {
        std::cout << q.front() << "\r\n";
        q.pop();
    }
}

int main()
{
    std::queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    std::queue<int> q2;
    q2.push(5);
    q2.push(6);
    q2.push(7);
    q2.push(8);

    q1.swap(q2);

    printAndEmptyIntQueue(q1);
    printAndEmptyIntQueue(q2);

    return 0;
}