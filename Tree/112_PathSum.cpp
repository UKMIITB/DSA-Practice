// https://leetcode.com/problems/path-sum/
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
    bool dfs(TreeNode *root, int currentSum, int targetSum)
    {
        if (root->left == NULL && root->right == NULL) // its a leaf node
            return (currentSum + root->val == targetSum);

        bool isLeftSum = false;
        bool isRightSum = false;

        if (root->left != NULL)
            isLeftSum = dfs(root->left, currentSum + root->val, targetSum);

        if (root->right != NULL)
            isRightSum = dfs(root->right, currentSum + root->val, targetSum);

        if (isLeftSum || isRightSum)
            return true;
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL) // there is only root, check if it is equal to sum
            return (root->val == targetSum);

        return dfs(root, 0, targetSum);
    }
};