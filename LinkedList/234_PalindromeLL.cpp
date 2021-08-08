// https://leetcode.com/problems/palindrome-linked-list/
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

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    stack<int> stackValues;

    while (fast != NULL && fast->next != NULL)
    {
        stackValues.push(slow->val);
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast != NULL) // odd length, so move one step ahead
        slow = slow->next;

    while (slow != NULL)
    {
        if (slow->val != stackValues.top())
            return false;

        slow = slow->next;
        stackValues.pop();
    }

    return true;
}