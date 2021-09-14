// https://leetcode.com/problems/sum-of-left-leaves/
#include <iostream>
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
    int getLeftLeavesSum(TreeNode *root, int sum, bool isLeftLeaf)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (isLeftLeaf)
                return sum + root->val;
            else
                return sum;
        }

        if (root->left != NULL)
        {
            sum = getLeftLeavesSum(root->left, sum, true);
        }
        if (root->right != NULL)
        {
            sum = getLeftLeavesSum(root->right, sum, false);
        }
        return sum;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        return getLeftLeavesSum(root, 0, false);
    }
};