// https://leetcode.com/problems/linked-list-random-node/
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

class Solution
{
    ListNode *head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int size = getSize();
        int randomIndex = rand() % size;
        ListNode *itr = head;

        for (int i = 0; i < randomIndex; i++)
        {
            itr = itr->next;
        }

        return itr->val;
    }

private:
    int getSize()
    {
        ListNode *itr = head;
        int count = 0;
        while (itr != NULL)
        {
            count++;
            itr = itr->next;
        }
        return count;
    }
};

int main()
{
    return 0;
}
