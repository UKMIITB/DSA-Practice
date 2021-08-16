// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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

int getSize(ListNode *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

ListNode *swapNodes(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    int count = 1;
    int size = getSize(head);

    ListNode *itr = head;

    ListNode *nodeLeft = NULL;
    ListNode *nodeRight = NULL;

    while (itr != NULL)
    {
        if (count == k)
            nodeLeft = itr;
        if (count == (size - k + 1))
            nodeRight = itr;

        count++;
        itr = itr->next;

        if (nodeLeft != NULL && nodeRight != NULL) // found both the nodes, now just swap
            break;
    }

    int leftVal = nodeLeft->val;
    nodeLeft->val = nodeRight->val;
    nodeRight->val = leftVal;

    return head;
}

int main()
{
    return 0;
}