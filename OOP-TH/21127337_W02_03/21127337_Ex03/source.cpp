#include "header.h"

void LinkedListQueue::init(int _capacity)
{
    head = tail = NULL;
    capacity = _capacity;
    num = 0;
}
void LinkedListQueue::output()
{
    cout << "Your queue is: ";
    Node *t = head;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
void LinkedListQueue::enqueue(int x)
{
    num++;
    if (isFull())
        return;
    Node *t = new Node(x);
    if (tail == NULL)
    {
        head = tail = t;
        return;
    }
    tail->next = t;
    tail = t;
}
int LinkedListQueue::dequeue()
{
    int x = -1;
    num--;
    if (head == NULL)
        return x;
    Node *t = head;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    x = t->data;
    delete t;
    return x;
}

int LinkedListQueue::peek()
{
    return head->data;
}

bool LinkedListQueue::isEmpty()
{
    return num == 0;
}

bool LinkedListQueue::isFull()
{
    return num == capacity;
}
void LinkedListQueue::clear()
{
    while (!isEmpty())
        dequeue();
}