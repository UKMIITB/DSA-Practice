// https://leetcode.com/problems/add-two-numbers-ii/
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

void reverseLinkedList(ListNode **head)
{
    if ((*head) == NULL || (*head)->next == NULL)
        return;

    ListNode *prev = NULL;
    ListNode *current = (*head);
    ListNode *temp = NULL;

    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    *head = prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    reverseLinkedList(&l1);
    reverseLinkedList(&l2);

    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;
    int carryOver = 0;
    int sum = 0;

    while (l1 != NULL || l2 != NULL)
    {
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carryOver;

        current->next = new ListNode(sum % 10);
        carryOver = sum / 10;

        sum = 0;
        current = current->next;
    }

    while (carryOver != 0)
    {
        current->next = new ListNode(carryOver % 10);
        carryOver /= 10;
    }

    ListNode *finalHead = dummy->next;
    reverseLinkedList(&finalHead);
    return finalHead;
}

// using stack
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // instead of direct reversing the list, add in stack & then go on adding top elements & in the end reverse the answer list
    return NULL;
}

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

//without reversing original list and without using stack
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    int n1 = getLinkedListSize(&l1);
    int n2 = getLinkedListSize(&l2);

    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (n1 != 0 || n2 != 0)
    {
        if (n1 == n2)
        {
            current->next = new ListNode(l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;

            n1--;
            n2--;
        }
        else if (n1 > n2)
        {
            current->next = new ListNode(l1->val);
            n1--;
            l1 = l1->next;
        }
        else // n2 > n1
        {
            current->next = new ListNode(l2->val);
            n2--;
            l2 = l2->next;
        }
        current = current->next;
    }
    ListNode *head = dummy->next;
    reverseLinkedList(&head);
    current = head;
    int carryOver = 0;
    int sum = 0;

    if (current->next == NULL)
    {
        sum = carryOver + current->val;
        current->val = sum % 10;
        carryOver = sum / 10;

        current = current->next;
    }
    else
    {
        while (current->next != NULL)
        {
            sum = carryOver + current->val;
            current->val = sum % 10;
            carryOver = sum / 10;

            current = current->next;
        }
    }

    while (carryOver != 0)
    {
        if (current == NULL)
            current = new ListNode(0);

        sum = carryOver + current->val;
        current->val = sum % 10;
        carryOver = sum / 10;

        current = current->next;
    }

    reverseLinkedList(&head);
    return head;
}

int main()
{
    ListNode *l1 = new ListNode(5);
    // l1->next = new ListNode(4);
    // l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);

    ListNode *sum = addTwoNumbers(l1, l2);

    while (sum != NULL)
    {
        cout << sum->val << endl;
        sum = sum->next;
    }
    return 0;
}
