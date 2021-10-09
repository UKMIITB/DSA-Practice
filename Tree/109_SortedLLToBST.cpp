// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// *** Important Question ***
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *getBSTFromSortedLL(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *mid = NULL;
        while (fast->next != tail && fast->next->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow;

        TreeNode *root = new TreeNode(mid->val);
        root->left = getBSTFromSortedLL(head, mid);
        root->right = getBSTFromSortedLL(mid->next, tail);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        return getBSTFromSortedLL(head, NULL);
    }
};