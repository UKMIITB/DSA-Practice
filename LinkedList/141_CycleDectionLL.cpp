// https://leetcode.com/problems/linked-list-cycle/
#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// using map solution
bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    unordered_map<ListNode *, int> map;
    int pos = 0;
    while (head != NULL)
    {
        if (map.count(head) == 1)
            return true;
        map.insert(make_pair(head, pos++));
        head = head->next;
    }

    return false;
}

//using slow fast method
bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    return 0;
}