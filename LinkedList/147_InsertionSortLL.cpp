// https://leetcode.com/problems/insertion-sort-list/
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

static bool compare(ListNode *&node1, ListNode *&node2)
{
    return node1->val < node2->val;
}

// using inbuilt sort
ListNode *insertionSortList(ListNode *head)
{
    vector<ListNode *> mVector;
    while (head != NULL)
    {
        mVector.push_back(head);
        head = head->next;
    }

    sort(mVector.begin(), mVector.end(), compare);

    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    for (int i = 0; i < mVector.size(); i++)
    {
        current->next = mVector.at(i);
        current = current->next;
    }
    current->next = NULL;

    return dummy->next;
}

// actual insertion sort
ListNode *insertionSortList(ListNode *head)
{
}

int main()
{
}