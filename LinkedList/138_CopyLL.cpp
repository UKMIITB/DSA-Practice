// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <iostream>
#include <unordered_map>
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
    unordered_map<Node *, Node *> map;
    Node *dummy = new Node(0);
    Node *current = dummy;

    Node *headItr = head;

    while (headItr != NULL)
    {

        current->next = new Node(headItr->val);
        map.insert(make_pair(headItr, current->next));

        current = current->next;
        headItr = headItr->next;
    }
    headItr = head;
    current = dummy->next;

    while (headItr != NULL)
    {
        if (headItr->random == NULL)
            current->random = NULL;
        else
            current->random = map[headItr->random];

        //updating to next value
        headItr = headItr->next;
        current = current->next;
    }

    return dummy->next;
}

int main()
{
    return 0;
}