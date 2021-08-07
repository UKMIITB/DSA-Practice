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
    ListNode *dummyHead = NULL;
    ListNode *dummyCurrent = dummyHead;
    ListNode *current = head;

    while (current != NULL)
    {
        if (current->next == NULL || current->next->val != current->val)
        {
            if (dummyHead == NULL)
            {
                dummyHead = new ListNode(current->val);
                dummyCurrent = dummyHead;
            }
            else
            {
                dummyCurrent->next = new ListNode(current->val);
                dummyCurrent = dummyCurrent->next;
            }

            current = current->next;
        }
        else
        {
            if (current->val == current->next->val)
            {
                int val = current->val;
                while (current != NULL && current->val == val)
                    current = current->next;
            }
        }
    }

    return dummyHead;
}