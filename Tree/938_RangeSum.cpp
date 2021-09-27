// https://leetcode.com/problems/range-sum-of-bst/
#include <iostream>
#include <queue>
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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);
        int sum = 0;

        while (!pendingNodes.empty())
        {
            int currentSize = pendingNodes.size();
            for (int i = 1; i <= currentSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();

                if (current->left && current->val >= low)
                    pendingNodes.push(current->left);

                if (current->right && current->val <= high)
                    pendingNodes.push(current->right);

                if (current->val >= low && current->val <= high)
                    sum = sum + current->val;
            }
        }
        return sum;
    }
};