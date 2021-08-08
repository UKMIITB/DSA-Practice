// https://leetcode.com/problems/intersection-of-two-linked-lists/
#include <iostream>
#include <math.h>
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;

    int lengthA = 0;
    int lengthB = 0;
    ListNode *currentA = headA;
    ListNode *currentB = headB;

    while (currentA != NULL)
    {
        lengthA++;
        currentA = currentA->next;
    }

    while (currentB != NULL)
    {
        lengthB++;
        currentB = currentB->next;
    }

    currentA = headA;
    currentB = headB;

    for (int i = 1; i <= abs(lengthA - lengthB); i++)
    {
        if (lengthA > lengthB)
            currentA = currentA->next;
        else
            currentB = currentB->next;
    }

    while (currentA != NULL)
    {
        if (currentA == currentB)
            return currentA;
        else
        {
            currentA = currentA->next;
            currentB = currentB->next;
        }
    }

    return NULL;
}