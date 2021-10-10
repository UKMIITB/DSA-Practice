// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    void getKthSmallest(TreeNode *root, int &k, int &KthSmallest)
    {
        if (root == NULL)
            return;

        getKthSmallest(root->left, k, KthSmallest);
        if (--k == 0)
            KthSmallest = root->val;
        getKthSmallest(root->right, k, KthSmallest);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int KthSmallest = -1;
        getKthSmallest(root, k, KthSmallest);
        return KthSmallest;
    }
};