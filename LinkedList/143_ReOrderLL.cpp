// https://leetcode.com/problems/reorder-list/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == NULL) //odd length, mid point is at slow
            break;

        if (fast->next == NULL) // even length, mid point is at slow
            break;
    }

    stack<ListNode *> mStack;
    queue<ListNode *> mQueue;
    bool startStoringInStack = false;

    slow = slow->next;

    ListNode *itr = head;
    while (itr != NULL)
    {
        if (itr == slow) // start storing in stack
        {
            startStoringInStack = true;
        }
        if (startStoringInStack)
            mStack.push(itr);
        else
            mQueue.push(itr);

        itr = itr->next;
    }

    // As head is already at 1st value and it doesn't need to be reordered
    mQueue.pop();
    itr = head;

    while (!mStack.empty() || !mQueue.empty())
    {
        if (!mStack.empty())
        {
            itr->next = mStack.top();
            itr = itr->next;
            mStack.pop();
        }

        if (!mQueue.empty())
        {
            itr->next = mQueue.front();
            itr = itr->next;
            mQueue.pop();
        }
    }
    itr->next = NULL; // VVI
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    reorderList(head);
    return 0;
}