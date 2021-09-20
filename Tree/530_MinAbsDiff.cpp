// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
#include <iostream>
#include <queue>
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
    int getMinimumDifference(TreeNode *root)
    {
        int minDiff = INT_MAX;
        queue<TreeNode *> pendingNodes;
        vector<int> values;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode *current = pendingNodes.front();
            pendingNodes.pop();
            values.push_back(current->val);

            if (current->left != NULL)
            {
                pendingNodes.push(current->left);
            }

            if (current->right != NULL)
            {
                pendingNodes.push(current->right);
            }
        }
        sort(values.begin(), values.end());
        for (int i = 1; i < values.size(); i++)
            minDiff = min(minDiff, abs(values[i] - values[i - 1]));
        return minDiff;
    }
};

// without using sorting [inorder traversal returns sorted values]
class Solution
{
public:
    void getInorderTraversal(TreeNode *root, vector<int> &sortedOrderValues)
    {
        if (root->left != NULL)
            getInorderTraversal(root->left, sortedOrderValues);

        sortedOrderValues.push_back(root->val);

        if (root->right != NULL)
            getInorderTraversal(root->right, sortedOrderValues);
    }

    int getMinimumDifference(TreeNode *root)
    {
        vector<int> sortedOrderValues;
        getInorderTraversal(root, sortedOrderValues);

        int minDiff = INT_MAX;
        for (int i = 1; i < sortedOrderValues.size(); i++)
            minDiff = min(minDiff, abs(sortedOrderValues[i] - sortedOrderValues[i - 1]));
        return minDiff;
    }
};