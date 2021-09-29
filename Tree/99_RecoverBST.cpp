// https://leetcode.com/problems/recover-binary-search-tree/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
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
    void recoverTree(TreeNode *root)
    {
        stack<TreeNode *> pendingNodes;
        vector<int> inOrderValues;
        TreeNode *current = root;
        while (current != NULL || !pendingNodes.empty())
        {
            while (current != NULL)
            {
                pendingNodes.push(current);
                current = current->left;
            }
            current = pendingNodes.top();
            pendingNodes.pop();
            inOrderValues.push_back(current->val);
            current = current->right;
        }

        sort(inOrderValues.begin(), inOrderValues.end());
        int index = 0;
        current = root;
        while (current != NULL || !pendingNodes.empty())
        {
            while (current != NULL)
            {
                pendingNodes.push(current);
                current = current->left;
            }
            current = pendingNodes.top();
            pendingNodes.pop();
            current->val = inOrderValues[index++];
            current = current->right;
        }
    }
};

// 2nd solution, using O(1) space
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *current = root;
        TreeNode *prev = new TreeNode(INT_MIN);
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        stack<TreeNode *> pendingNodes;

        while (current != NULL || !pendingNodes.empty())
        {
            while (current != NULL)
            {
                pendingNodes.push(current);
                current = current->left;
            }
            current = pendingNodes.top();
            pendingNodes.pop();

            if (first == NULL && prev->val > current->val)
                first = prev;

            if (first != NULL && prev->val > current->val)
                second = current;

            prev = current;
            current = current->right;
        }
        swap(first->val, second->val);
    }
};