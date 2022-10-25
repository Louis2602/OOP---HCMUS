#include "header.h"

int main()
{
    LinkedListQueue q;
    q.init(7);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(6);
    q.output();
    // 3 2 5 7 8 6
    int x;
    x = q.dequeue();
    cout << "Dequeue: " << x << endl; // 3
    q.output();
    // 2 5 7 8 6
    cout << "Enqueue 12 and 21\n";
    q.enqueue(12);
    q.enqueue(21);
    q.output();
    x = q.dequeue();
    cout << "Dequeue: " << x << endl; // 3
    q.output();
    // 2 5 7 8 6 12 21 = 7
    cout << "Peek value of queue: " << q.peek() << endl; // 2
    cout << "Queue is full? : " << q.isFull() << endl;   // true
    cout << "Queue is empty? : " << q.isEmpty() << endl; // no
    q.clear();
    cout << "After clear, Queue is empty? : " << q.isEmpty() << endl; // no
    return 0;
}