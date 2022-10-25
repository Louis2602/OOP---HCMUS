#pragma once

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int key)
    {
        data = key;
        next = NULL;
    }
};

class LinkedListQueue
{
    Node *head;
    Node *tail;
    int capacity;
    int num;

public:
    void init(int capacity);
    void output();
    void enqueue(int x);
    int dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};