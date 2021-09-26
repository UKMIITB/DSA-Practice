// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    void getInOrderValues(TreeNode *root, vector<int> &inOrderValues)
    {
        if (root == NULL)
            return;

        getInOrderValues(root->left, inOrderValues);
        inOrderValues.push_back(root->val);
        getInOrderValues(root->right, inOrderValues);
    }

    int minDiffInBST(TreeNode *root)
    {
        vector<int> inOrderValues;
        getInOrderValues(root, inOrderValues);

        int minDiff = INT_MAX;
        for (int i = 1; i < inOrderValues.size(); i++)
        {
            minDiff = min(minDiff, abs(inOrderValues[i] - inOrderValues[i - 1]));
        }
        return minDiff;
    }
};