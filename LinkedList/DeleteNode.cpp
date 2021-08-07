// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include <iostream>
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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *countCopy = head;
    int count = 0;
    while (countCopy != NULL)
    {
        count++;
        countCopy = countCopy->next;
    }

    countCopy = head;

    for (int i = 2; i < count - n + 1; i++) // stopping just before
    {
        countCopy = countCopy->next;
    }
    if (count == 1)
    {
        head = NULL;
    }
    else if (n == count)
    {
        head = head->next;
    }
    else if (n == 1)
    {
        countCopy->next = NULL;
    }
    else
    {
        countCopy->next = countCopy->next->next;
    }

    return head;
}