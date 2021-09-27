// https://leetcode.com/problems/increasing-order-search-tree/
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
    void getInorder(TreeNode *root, vector<int> &inOrder)
    {
        if (root == NULL)
            return;

        getInorder(root->left, inOrder);
        inOrder.push_back(root->val);
        getInorder(root->right, inOrder);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> inOrderValues;
        getInorder(root, inOrderValues);

        TreeNode *mRoot = NULL;
        TreeNode *current = NULL;
        for (auto val : inOrderValues)
        {
            if (mRoot == NULL) // its the 1st value
            {
                mRoot = new TreeNode(val);
                current = mRoot;
            }
            else
            {
                current->right = new TreeNode(val);
                current = current->right;
            }
        }
        return mRoot;
    }
};