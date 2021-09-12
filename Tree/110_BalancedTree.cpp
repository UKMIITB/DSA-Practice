// https://leetcode.com/problems/balanced-binary-tree/
#include <iostream>
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
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;

        if (root->left == NULL && root->right == NULL)
            return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
};