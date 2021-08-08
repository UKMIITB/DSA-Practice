// https://leetcode.com/problems/remove-linked-list-elements/
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

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode *pre = dummyHead;
    ListNode *current = dummyHead->next;

    while (current != NULL)
    {
        if (current->val == val)
        {
            pre->next = NULL;
            current = current->next;
        }
        else
        {
            pre->next = current;
            pre = pre->next;
            current = current->next;
        }
    }

    return dummyHead->next;
}