// https://leetcode.com/problems/insertion-sort-list/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static bool compare(ListNode *&node1, ListNode *&node2)
{
    return node1->val < node2->val;
}

// using inbuilt sort
ListNode *insertionSortList(ListNode *head)
{
    vector<ListNode *> mVector;
    while (head != NULL)
    {
        mVector.push_back(head);
        head = head->next;
    }

    sort(mVector.begin(), mVector.end(), compare);

    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    for (int i = 0; i < mVector.size(); i++)
    {
        current->next = mVector.at(i);
        current = current->next;
    }
    current->next = NULL;

    return dummy->next;
}

void placeCurrentAtCorrectPosition(ListNode **head, ListNode **swapCurrent)
{
    ListNode *itr = *head;
    ListNode *prev = NULL;
    int index = 0;

    while (itr != *swapCurrent)
    {
        if ((*swapCurrent)->val < itr->val)
        {
            if (index == 0) // this is new head
            {
                (*swapCurrent)->next = *head;
                *head = *swapCurrent;
            }
            else
            {
                prev->next = *swapCurrent;
                (*swapCurrent)->next = itr;
            }
            break;
        }
        prev = itr;
        itr = itr->next;

        index++;
    }
}

// actual insertion sort
ListNode *insertionSortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *prev = head;
    ListNode *current = head->next;

    while (current != NULL)
    {
        if (current->val < prev->val)
        {
            ListNode *swapCurrent = current;
            current = current->next;
            placeCurrentAtCorrectPosition(&head, &swapCurrent);
            prev->next = current;
        }
        else
        {
            current = current->next;
            prev = prev->next;
        }
    }
    return head;
}

int main()
{
}