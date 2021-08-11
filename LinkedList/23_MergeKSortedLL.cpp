// https://leetcode.com/problems/merge-k-sorted-lists/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int addMinToCurrentAndReturnCount(vector<ListNode *> &lists, ListNode **current)
{
    int minVal = INT_MAX;
    int index = 0;
    int countNull = 0;

    for (int i = 0; i < lists.size(); i++)
    {
        if (lists.at(i) == NULL)
            countNull++;
        else
        {
            if (lists.at(i)->val < minVal)
            {
                minVal = lists.at(i)->val;
                index = i;
            }
        }
    }

    if (countNull == lists.size())
        (*current)->next = NULL;
    else
    {
        (*current)->next = lists.at(index);
        (*current) = (*current)->next;
        lists.at(index) = lists.at(index)->next;
    }

    return countNull;
}

// direct iteration
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    int countNull = 0;

    while (countNull != lists.size())
    {
        countNull = addMinToCurrentAndReturnCount(lists, &current);
    }

    return dummy->next;
}

struct compare
{
    bool operator()(ListNode *&node1, ListNode *&node2)
    {
        return node1->val < node2->val;
    }
};

//using priority queue
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    ListNode *iterateHead = NULL;

    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    for (int i = 0; i < lists.size(); i++)
    {
        iterateHead = lists[i];
        while (iterateHead != NULL)
        {
            pq.push(iterateHead);
            iterateHead = iterateHead->next;
        }
    }

    while (!pq.empty())
    {
        current->next = pq.top();
        pq.pop();
        current = current->next;
    }

    return dummy->next;
}

int main()
{
    return 0;
}