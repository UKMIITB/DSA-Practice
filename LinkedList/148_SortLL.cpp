// https://leetcode.com/problems/sort-list/
#include <iostream>
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

int main()
{
    return 0;
}

struct compare
{
    bool operator()(int &num1, int &num2)
    {
        return num1 < num2;
    }
};

ListNode *sortList(ListNode *head)
{
    priority_queue<int, vector<int>, compare> pq;
    ListNode *current = head;

    while (current != NULL)
    {
        pq.push(current->val);
        current = current->next;
    }

    current = head;
    while (current != NULL)
    {
        current->val = pq.top();
        pq.pop();
        current = current->next;
    }

    return head;
}