// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *current = head;
    ListNode *dummyHead = new ListNode(0);
    ListNode *pre = dummyHead;

    while (current && current->next)
    {
        if (current->val == current->next->val)
        {
            while (current->next && current->val == current->next->val)
            {
                current = current->next;
            }
        }
        pre->next = current;
        pre = current;
        current = current->next;
    }

    return dummyHead->next;
}