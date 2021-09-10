// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
#include <iostream>
#include <queue>
using namespace std;

class Solution
{
    queue<int> q;

public:
    int findTheWinner(int n, int k)
    {
        for (int i = 1; i <= n; i++)
            q.push(i);

        while (q.size() != 1)
        {
            for (int i = 1; i < k; i++)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};

// linked list solution
struct Node
{
    int val;
    Node *next;
    Node()
    {
        this->val = 0;
        this->next = NULL;
    }
    Node(int _val, Node *_next)
    {
        this->val = _val;
        this->next = _next;
    }
    Node(int _val)
    {
        this->val = _val;
        this->next = NULL;
    }
};

Node *head;
Node *current;
int currentSize;

int findTheWinner(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (head == NULL)
        {
            head = new Node(i);
            current = head;
            currentSize = n;
        }
        else
        {
            current->next = new Node(i);
            current = current->next;
        }
    }

    current->next = head; // making it circular linked list

    if (k == 1) // self delete case so return the last value
        return current->val;

    while (currentSize != 1)
    {
        for (int i = 2; i < k; i++) // moving just before the delete node
            head = head->next;

        Node *toDelete = head->next;
        head->next = head->next->next;
        head = head->next;
        delete toDelete;
        currentSize--;
    }

    return head->val;
}

int main()
{
    int winner = findTheWinner(5, 2);
    return 0;
}