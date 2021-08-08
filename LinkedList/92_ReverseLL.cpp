// https://leetcode.com/problems/reverse-linked-list-ii/
#include <iostream>
#include <stack>
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

void insertNode(ListNode **head, ListNode **current, int val)
{
    if (*head == NULL)
    {
        *head = new ListNode(val);
        *current = *head;
    }
    else
    {
        (*current)->next = new ListNode(val);
        *current = (*current)->next;
    }
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right)
        return head;

    ListNode *finalHead = NULL;
    ListNode *current = NULL;
    int count = 1;
    stack<int> toAddValues;

    while (head != NULL)
    {
        if (count >= left && count <= right)
        {
            while (count <= right)
            {
                toAddValues.push(head->val);
                count++;
                head = head->next;
            }

            while (!toAddValues.empty())
            {
                insertNode(&finalHead, &current, toAddValues.top());
                toAddValues.pop();
            }
        }
        else
        {
            insertNode(&finalHead, &current, head->val);
            head = head->next;
            count++;
        }
    }

    return finalHead;
}