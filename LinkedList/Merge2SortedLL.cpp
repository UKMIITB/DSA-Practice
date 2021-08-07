// https://leetcode.com/problems/merge-two-sorted-lists/
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

void insertNode(ListNode **finalHead, ListNode **currentNode, int val)
{
    if (*finalHead == NULL)
    {
        *finalHead = new ListNode(val);
        *currentNode = *finalHead;
    }
    else
    {
        (*currentNode)->next = new ListNode(val);
        (*currentNode) = (*currentNode)->next;
    }
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *finalHead = NULL;
    ListNode *currentNode = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        int val = 0;
        if (l1->val < l2->val)
        {
            val = l1->val;
            l1 = l1->next;
        }
        else
        {
            val = l2->val;
            l2 = l2->next;
        }

        insertNode(&finalHead, &currentNode, val);
    }

    while (l1 != NULL)
    {
        insertNode(&finalHead, &currentNode, l1->val);
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        insertNode(&finalHead, &currentNode, l2->val);
        l2 = l2->next;
    }

    return finalHead;
}