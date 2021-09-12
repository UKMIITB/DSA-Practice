// https://leetcode.com/problems/same-tree/
#include <iostream>
#include <queue>
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
    vector<int> getLevelWiseValues(TreeNode *root)
    {
        queue<TreeNode *> pendingNodes;
        vector<int> levelWiseValue;

        pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            TreeNode *curr = pendingNodes.front();
            pendingNodes.pop();

            if (curr == NULL)
                levelWiseValue.push_back(-1);
            else
            {
                levelWiseValue.push_back(curr->val);
                pendingNodes.push(curr->left);
                pendingNodes.push(curr->right);
            }
        }

        return levelWiseValue;
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;

        vector<int> levelWiseP = getLevelWiseValues(p);
        vector<int> levelwiseQ = getLevelWiseValues(q);

        if (levelWiseP == levelwiseQ)
            return true;
        else
            return false;
    }
};

// using recursive solution
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}