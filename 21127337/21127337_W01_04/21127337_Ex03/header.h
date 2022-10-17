#pragma once

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

public:
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
    void enqueue(int x);
    void dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    void clear();
};