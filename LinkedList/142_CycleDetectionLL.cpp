//https://leetcode.com/problems/linked-list-cycle-ii/
#include <iostream>
#include <unordered_map>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//using map based solution
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    unordered_map<ListNode *, ListNode *> map;
    while (head != NULL)
    {
        if (map.count(head) == 1)
            return map.at(head);

        map.insert(make_pair(head, head));

        head = head->next;
    }

    return NULL;
}

//https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycleDetected = false;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            isCycleDetected = true;
            break;
        }
    }

    if (isCycleDetected == false)
        return NULL;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    return 0;
}