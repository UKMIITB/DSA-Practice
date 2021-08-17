// https://leetcode.com/problems/linked-list-components/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int numComponents(ListNode *head, vector<int> &nums)
{
    unordered_set<int> mSet(nums.begin(), nums.end());
    int count = 0;
    bool isExist = false;

    while (head != NULL)
    {
        if (mSet.count(head->val) == 1)
        {
            if (isExist == false)
                count++;

            isExist = true;
        }
        else
            isExist = false;

        head = head->next;
    }

    return count;
}