// https://leetcode.com/problems/odd-even-linked-list/
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

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    int position = 1; // first is odd

    ListNode *oddHead = new ListNode(0);
    ListNode *oddCurrent = oddHead;

    ListNode *evenHead = new ListNode(0);
    ListNode *evenCurrent = evenHead;

    while (head != NULL)
    {
        if (position == 1) // odd
        {
            oddCurrent->next = head;

            //updating variables
            oddCurrent = oddCurrent->next;
            position = 0; //next is even
        }
        else
        {
            evenCurrent->next = head;
            evenCurrent = evenCurrent->next;
            position = 1; //next is odd
        }
        head = head->next;
    }

    // reseting the endpoints as null
    oddCurrent->next = NULL;
    evenCurrent->next = NULL;

    // connecting the endpoints
    oddCurrent->next = evenHead->next;

    return oddHead->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    ListNode *answer = oddEvenList(head);

    while (answer != NULL)
    {
        cout << answer->val << endl;
        answer = answer->next;
    }

    return 0;
}