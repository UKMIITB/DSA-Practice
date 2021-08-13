// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *dummy = new Node(0);
    Node *current = dummy;

    while (head != NULL)
    {
        current->next = new Node(head->val);
        current->random = head->random;

        current = current->next;
        head = head->next;
    }

    return dummy->next;
}

int main()
{
    return 0;
}