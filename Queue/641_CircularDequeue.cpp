// https://leetcode.com/problems/design-circular-deque/
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *pre;
    Node *next;
    Node(int _value)
    {
        value = _value;
        pre = NULL;
        next = NULL;
    }
    Node(int _value, Node *_pre, Node *_next)
    {
        value = _value;
        pre = _pre;
        next = _next;
    }
};

class MyCircularDeque
{
    Node *head;
    Node *tail;
    int size;
    int capacity;

public:
    MyCircularDeque(int k)
    {
        head = NULL;
        tail = NULL;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value)
    {
        if (size >= capacity) // size is full, can't insert more
            return false;

        if (size == 0) // it has to be inserted at head
        {
            head = new Node(value, NULL, tail);
            tail = head;
        }
        else
        {
            head->pre = new Node(value, NULL, head); // head pre is connected to new node & new node next is connected to head
            head = head->pre;
        }

        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (size >= capacity) // size is full, can't insert more
            return false;

        if (size == 0) // it has to be inserted at head
        {
            head = new Node(value, NULL, tail);
            tail = head;
        }
        else
        {
            tail->next = new Node(value, tail, NULL); // tail next is connected to new node & new node pre is connected to tail
            tail = tail->next;
        }

        size++;
        return true;
    }

    bool deleteFront()
    {
        if (size <= 0) // no element to delete
            return false;

        Node *toDelete = head;
        head = head->next;

        delete toDelete;

        if (head != NULL) // if size is now 0 then don't need to set pre as NULL
            head->pre = NULL;

        size--;
        return true;
    }

    bool deleteLast()
    {
        if (size <= 0) // no element to delete
            return false;

        Node *toDelete = tail;
        tail = tail->pre;

        delete toDelete;

        if (tail != NULL) // if size is now 0 then don't need to set pre as NULL
            tail->next = NULL;

        size--;
        return true;
    }

    int getFront()
    {
        if (size <= 0)
            return -1;

        return head->value;
    }

    int getRear()
    {
        if (size <= 0)
            return -1;

        return tail->value;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    bool isFull()
    {
        return (size == capacity);
    }
};

int main()
{
    MyCircularDeque *obj = new MyCircularDeque(8);
    cout << obj->insertFront(5);
    cout << obj->getFront();
    cout << obj->isEmpty();
    cout << obj->deleteFront();
    cout << obj->insertLast(3);
    cout << obj->getRear();
    cout << obj->insertLast(7);
    cout << obj->insertFront(7);
    cout << obj->deleteLast();
    cout << obj->insertLast(4);
    cout << obj->isEmpty();

    return 0;
}