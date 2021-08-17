// https://leetcode.com/problems/split-linked-list-in-parts/
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

int getLinkedListSize(ListNode **head)
{
    int count = 0;
    ListNode *itr = *head;

    while (itr != NULL)
    {
        count++;
        itr = itr->next;
    }

    return count;
}

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    int size = getLinkedListSize(&head);
    vector<ListNode *> mVector;

    int eachSize = size / k;
    int remainder = size % k;

    int currentSize = 0;

    for (int i = 1; i <= k; i++)
    {
        if (remainder != 0)
        {
            currentSize = eachSize + 1;
            remainder--;
        }
        else
            currentSize = eachSize;

        if (head == NULL)
        {
            mVector.push_back(NULL);
        }
        else
        {
            ListNode *dummy = new ListNode(0);
            ListNode *current = dummy;

            while (currentSize-- != 0)
            {
                current->next = head;
                head = head->next;
                current = current->next;
            }
            current->next = NULL;
            mVector.push_back(dummy->next);
        }
    }

    return mVector;
}

int main()
{
    return 0;
}