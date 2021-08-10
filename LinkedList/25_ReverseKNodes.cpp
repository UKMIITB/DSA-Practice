// https://leetcode.com/problems/reverse-nodes-in-k-group/
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

int main()
{
    return 0;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;

    ListNode *dummy = new ListNode(0);
    ListNode *updatedHead = dummy->next;

    ListNode *current = head;
    ListNode *start = head;
    ListNode *end = NULL;

    int count = 1;
    while (current != NULL)
    {
        if (count == k)
        {
            end = current;           // till here reversing would be done
            current = current->next; // move to end + 1
            customReverse(&start, &end);

            dummy->next = end;
            dummy = start;
            start = current;
        }
        else
        {
            current = current->next;
        }
    }

    return updatedHead;
}