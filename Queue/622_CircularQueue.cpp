// https://leetcode.com/problems/design-circular-queue/
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node()
    {
        val = 0;
        next = NULL;
    }
    Node(int _val)
    {
        val = _val;
        next = NULL;
    }
    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};
class MyCircularQueue
{
    Node *head;
    Node *tail;
    int size;
    int capacity;

public:
    MyCircularQueue(int k)
    {
        head = NULL;
        tail = NULL;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value)
    {
        if (size >= capacity) // its full, can't insert, returning false
            return false;

        if (size == 0) // it will go at head
        {
            head = new Node(value);
            tail = head;
        }
        else // just tail needs to be updated
        {
            tail->next = new Node(value);
            tail = tail->next;
        }
        size++;
        return true;
    }

    bool deQueue()
    {
        if (size <= 0) // no element present
            return false;

        Node *toDelete = head; // this has to be deleted
        head = head->next;     // moving head forward
        delete toDelete;

        size--;
        return true;
    }

    int Front()
    {
        if (size <= 0)
            return -1;

        return head->val;
    }

    int Rear()
    {
        if (size <= 0)
            return -1;

        return tail->val;
    }

    bool isEmpty()
    {
        return (size <= 0);
    }

    bool isFull()
    {
        return (size == capacity);
    }
};

int main()
{
    MyCircularQueue *myCircularQueue = new MyCircularQueue(3);
    cout << myCircularQueue->enQueue(1); // return True
    cout << myCircularQueue->enQueue(2); // return True
    cout << myCircularQueue->enQueue(3); // return True
    cout << myCircularQueue->enQueue(4); // return False
    cout << myCircularQueue->Rear();     // return 3
    cout << myCircularQueue->isFull();   // return True
    cout << myCircularQueue->deQueue();  // return True
    cout << myCircularQueue->enQueue(4); // return True
    cout << myCircularQueue->Rear();     // return 4
    return 0;
}