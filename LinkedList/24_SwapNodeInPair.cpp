// https://leetcode.com/problems/swap-nodes-in-pairs/
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

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL)
        return head;

    if (head->next == NULL)
        return head;

    ListNode *prev = head;
    ListNode *current = head->next;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *switchNode = dummy;

    while (current != NULL)
    {
        prev->next = current->next;
        current->next = prev;
        switchNode->next = current;

        //updation
        switchNode = prev;
        prev = prev->next;
        if (prev != NULL)
            current = prev->next;
        else
            current = NULL;
    }
    return dummy->next;
}