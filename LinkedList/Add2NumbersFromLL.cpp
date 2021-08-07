// https://leetcode.com/problems/add-two-numbers/
#include <iostream>
#include <vector>
#include <unordered_map>
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

pair<int, int> valAndCarryOver(int num1, int num2)
{
    int val = (num1 + num2) % 10;
    int carryOver = (num1 + num2) / 10;
    return make_pair(val, carryOver);
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL;
    ListNode *current = NULL;
    int carryOver = 0;

    while (l1 != NULL && l2 != NULL)
    {
        pair<int, int> valAndCarry = valAndCarryOver(l1->val + carryOver, l2->val);

        insertNode(&head, &current, valAndCarry.first);

        carryOver = valAndCarry.second;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL)
    {
        pair<int, int> valAndCarry = valAndCarryOver(l1->val, carryOver);

        insertNode(&head, &current, valAndCarry.first);

        carryOver = valAndCarry.second;
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        pair<int, int> valAndCarry = valAndCarryOver(l2->val, carryOver);

        insertNode(&head, &current, valAndCarry.first);

        carryOver = valAndCarry.second;
        l2 = l2->next;
    }

    while (carryOver != 0)
    {
        pair<int, int> valAndCarry = valAndCarryOver(0, carryOver);

        insertNode(&head, &current, valAndCarry.first);

        carryOver = valAndCarry.second;
        carryOver /= 10;
    }

    return head;
}

int main()
{
    ListNode *head1 = new ListNode(2);
    ListNode *current1 = new ListNode(4);
    head1->next = current1;
    current1->next = new ListNode(3);

    ListNode *head2 = new ListNode(5);
    ListNode *current2 = new ListNode(6);
    head2->next = current2;
    current2->next = new ListNode(4);

    ListNode *headAnswer = addTwoNumbers(head1, head2);
    while (headAnswer != NULL)
    {
        cout << headAnswer->val << endl;
        headAnswer = headAnswer->next;
    }

    return 0;
}
