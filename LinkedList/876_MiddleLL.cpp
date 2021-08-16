// https://leetcode.com/problems/middle-of-the-linked-list/
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

ListNode *middleNode(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next == NULL) // odd size
        return slow;

    if (fast->next->next == NULL) // even size, returning 2nd element
        return slow->next;

    return slow;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    head = middleNode(head);
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}