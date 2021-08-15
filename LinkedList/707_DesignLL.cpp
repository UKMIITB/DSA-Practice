// https://leetcode.com/problems/design-linked-list/
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        this->val = -1;
        this->next = NULL;
    }

    Node(int _val)
    {
        this->val = _val;
        this->next = NULL;
    }

    Node(int _val, Node *_next)
    {
        this->val = _val;
        this->next = _next;
    }
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    Node *head;
    int size;

    MyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= this->size) // invalid index
            return -1;

        int count = 0;
        Node *itr = head;
        while (count < index)
        {
            itr = itr->next;
            count++;
        }
        return itr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        if (head == NULL)
            head = new Node(val);
        else
        {
            Node *newHead = new Node(val, head);
            head = newHead;
        }

        this->size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (head == NULL)
            head = new Node(val);
        else
        {
            Node *itr = head;
            while (itr->next != NULL)
            {
                itr = itr->next;
            }
            itr->next = new Node(val);
        }

        this->size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > this->size)
            return;

        if (this->size == 0) // adding at head
        {
            head = new Node(val);
            this->size++;
            return;
        }

        if (index == 0) // needs to be added before head
        {
            addAtHead(val);
            return;
        }

        int count = 0;
        Node *itr = head;

        if (index == this->size) //append at the end
        {
            while (itr->next != NULL)
                itr = itr->next;

            itr->next = new Node(val);
        }
        else //at a node in between
        {
            while (count < (index - 1))
            {
                itr = itr->next;
                count++;
            }

            Node *next = itr->next;
            itr->next = new Node(val, next);
        }
        this->size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= this->size) //invalid index
            return;

        if (this->size == 1)
        {
            head = NULL;
            this->size--;
            return;
        }

        if (index == 0)
        {
            head = head->next;
            this->size--;
            return;
        }

        int count = 0;
        Node *itr = head;

        while (count < index - 1)
        {
            itr = itr->next;
            count++;
        }

        Node *next = itr->next->next;
        itr->next = next;

        this->size--;
    }

    void print()
    {
        Node *itr = head;
        cout << endl
             << endl
             << endl;
        cout << "Printing begins ------>" << endl;
        cout << "Current size is ------>" << size << endl;
        while (itr != NULL)
        {
            cout << "Value is -------->" << itr->val << endl;
            itr = itr->next;
        }
    }

    ~MyLinkedList()
    {
        Node *prev = head;
        while (head != NULL)
        {
            prev = head;
            head = head->next;
            delete prev;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList *obj = new MyLinkedList();
    // obj->print();
    // obj->addAtHead(1);
    // obj->print();
    // obj->addAtTail(3);
    // obj->print();
    // obj->addAtIndex(1, 2);
    // obj->print();
    // obj->get(1);
    // obj->print();
    // obj->deleteAtIndex(1);
    // obj->print();
    // obj->get(1);
    // obj->print();

    obj->addAtHead(1);
    obj->addAtTail(3);

    obj->addAtIndex(1, 2);
    obj->print();
    obj->get(1);
    obj->deleteAtIndex(0);
    obj->print();
    obj->get(0);
}