// https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode *root, long minVal, long maxVal)
    {
        if (root == NULL)
            return true;

        if (root->val < minVal || root->val > maxVal)
            return false;

        long maxValForLeft = root->val;
        maxValForLeft--;

        long minValForRight = root->val;
        minValForRight++;

        bool isLeftBST = isValidBST(root->left, minVal, maxValForLeft);
        bool isRightBST = isValidBST(root->right, minValForRight, maxVal);
        return isLeftBST && isRightBST;
    }

    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};