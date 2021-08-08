// https://leetcode.com/problems/partition-list/
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

void insertNode(ListNode **head, ListNode **current, int val)
{
    if (*head == NULL)
    {
        *head = new ListNode(val);
        *current = *head;
    }
    else
    {
        (*current)->next = new ListNode(val);
        *current = (*current)->next;
    }
}

ListNode *partition(ListNode *head, int x)
{
    ListNode *leftHead = NULL;
    ListNode *leftCurrent = leftHead;

    ListNode *rightHead = NULL;
    ListNode *rightCurrent = rightHead;

    while (head != NULL)
    {
        if (head->val < x)
            insertNode(&leftHead, &leftCurrent, head->val);
        else
            insertNode(&rightHead, &rightCurrent, head->val);

        head = head->next;
    }

    if (leftCurrent == NULL)
        return rightHead;
    else if (rightCurrent == NULL)
        return leftHead;
    else
        leftCurrent->next = rightHead;

    return leftHead;
}
