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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;

    ListNode *dummy = new ListNode(0);
    ListNode *updatedHead = NULL;

    ListNode *current = head;
    ListNode *start = head;
    ListNode *end = NULL;

    int count = 1;
    while (current != NULL)
    {
        if (count == k)
        {
            end = current;           // till end reversing would be done
            current = current->next; // move to end + 1
            customReverse(&start, &end);

            dummy->next = end;

            if (updatedHead == NULL) // storing final head to be returned
                updatedHead = dummy->next;

            dummy = start;
            start = current;
            count = 1;
        }
        else
        {
            current = current->next;
            count++;
        }
    }

    if (count != 1) // last few nodes which are not multiples of k
        dummy->next = start;

    return updatedHead;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *reverseHead = reverseKGroup(head, 2);

    while (reverseHead != NULL)
    {
        cout << reverseHead->val << endl;
        reverseHead = reverseHead->next;
    }

    return 0;
}