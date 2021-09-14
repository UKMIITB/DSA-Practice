// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int lower = min(p->val, q->val);
        int higher = max(p->val, q->val);

        while (root != NULL)
        {
            if (root->val == lower || root->val == higher)
                return root;
            else if (root->val >= lower && root->val <= higher)
                return root;
            else
            {
                if (higher < root->val)
                    root = root->left;
                else
                    root = root->right;
            }
        }
        return nullptr;
    }
};

// better way iteratively
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int lower = min(p->val, q->val);
        int higher = max(p->val, q->val);

        while (true)
        {
            if (higher < root->val)
                root = root->left;
            else if (lower > root->val)
                root = root->right;
            else
                break;
        }

        return root;
    }
};