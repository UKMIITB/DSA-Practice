// https://leetcode.com/problems/binary-tree-tilt/
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
    int getTiltSum(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return 0;

        int leftTiltSum = getTiltSum(root->left, sum);
        int rightTiltSum = getTiltSum(root->right, sum);
        sum += abs(leftTiltSum - rightTiltSum);
        return leftTiltSum + rightTiltSum + root->val;
    }

    int findTilt(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int ans = 0;
        getTiltSum(root, ans);
        return ans;
    }
};