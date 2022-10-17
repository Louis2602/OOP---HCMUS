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
    // 3 2 5 7 8 6
    q.dequeue();
    // 2 5 7 8 6
    q.enqueue(12);
    q.enqueue(21);
    // 2 5 7 8 6 12 21 = 7
    cout << q.peek() << endl;    // 2
    cout << q.isFull() << endl;  // true
    cout << q.isEmpty() << endl; // no
    q.clear();
    cout << q.isEmpty() << endl; // yes
    return 0;
}