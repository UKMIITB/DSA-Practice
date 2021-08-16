// https://leetcode.com/problems/merge-in-between-linked-lists/
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

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    int index = 0;
    ListNode *start = NULL;
    ListNode *end = NULL;
    ListNode *itr = list1;

    while (itr != NULL)
    {
        if (index == a - 1) // its next would be connected to list2 head
            start = itr;

        if (index == b + 1) // here list2 tail would be connected
            end = itr;

        index++;
        itr = itr->next;

        if (start != NULL && end != NULL) // we have got end points
            break;
    }

    ListNode *tailList2 = list2;
    while (tailList2->next != NULL)
    {
        tailList2 = tailList2->next;
    }

    // make the connection
    start->next = list2;
    tailList2->next = end;

    return list1;
}

int main()
{
    return 0;
}