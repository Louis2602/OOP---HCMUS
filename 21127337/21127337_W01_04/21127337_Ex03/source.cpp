#include "header.h"

void LinkedListQueue::init(int _capacity)
{
    head = tail = NULL;
    capacity = _capacity;
    num = 0;
}

void LinkedListQueue::enqueue(int x)
{
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
    if (head == NULL)
        return;
    Node *t = head;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    int x = t->data;
    delete t;
    return x;
}

int LinkedListQueue::peek()
{
    return head->data;
}

bool LinkedListQueue::isEmpty()
{
    if (head == NULL || tail == NULL)
        return true;
    return false;
}

bool LinkedListQueue::isFull()
{
    Node *t = head;
    while (t)
    {
        num++;
        t = t->next;
    }
    return num == capacity;
}
void LinkedListQueue::clear()
{
    while (!isEmpty())
        dequeue();
}