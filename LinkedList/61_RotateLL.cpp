// https://leetcode.com/problems/rotate-list/
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

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *dummy = head;
    ListNode *tail = NULL;
    int count = 0;

    while (dummy != NULL)
    {
        count++;
        tail = dummy;
        dummy = dummy->next;
    }
    k = k % count;

    int newTailPos = count - k;

    if (newTailPos == 0 || k == 0)
        return head;

    dummy = head;

    for (int i = 1; i < newTailPos; i++)
    {
        dummy = dummy->next;
    }

    ListNode *newHead = dummy->next;
    dummy->next = NULL;
    tail->next = head;

    return newHead;
}