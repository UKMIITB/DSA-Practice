// https://leetcode.com/problems/leaf-similar-trees/
#include <iostream>
#include <vector>
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
    void getDFSLeaves(TreeNode *root, vector<int> &dfsLeaves)
    {
        if (root == NULL)
            return;

        getDFSLeaves(root->left, dfsLeaves);
        getDFSLeaves(root->right, dfsLeaves);
        if (root->left == NULL && root->right == NULL)
            dfsLeaves.push_back(root->val);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> root1Leaves;
        getDFSLeaves(root1, root1Leaves);

        vector<int> root2Leaves;
        getDFSLeaves(root2, root2Leaves);

        return root1Leaves == root2Leaves;
    }
};