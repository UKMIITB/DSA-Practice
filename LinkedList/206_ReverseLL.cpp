// https://leetcode.com/problems/reverse-linked-list/
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

// Recursion based solution
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *restReversedHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return restReversedHead;
}

// Iteration based solution
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *pre = NULL;
    ListNode *current = head;
    ListNode *temp;

    while (current != NULL)
    {
        temp = current->next;

        current->next = pre;
        pre = current;
        current = temp;
    }

    return pre;
}

//using function call
void customReverse(ListNode **start, ListNode **end)
{
    ListNode *prev = NULL;
    ListNode *current = *start;
    ListNode *next = NULL;

    while (current != *end)
    {
        next = current->next;
        current->next = prev;

        // updating
        prev = current;
        current = next;
    }
    current->next = prev;
}

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *end = head;
    while (end->next != NULL)
        end = end->next;

    customReverse(&head, &end);
    return end;
}