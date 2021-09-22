// https://leetcode.com/problems/subtree-of-another-tree/
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
    bool isPerfectSubTree(TreeNode *root, TreeNode *subroot)
    {
        if (root == NULL && subroot == NULL)
            return true;

        if ((root == NULL && subroot != NULL) || (root != NULL && subroot == NULL))
            return false;

        if (root->val == subroot->val && isPerfectSubTree(root->left, subroot->left) && isPerfectSubTree(root->right, subroot->right))
            return true;
        else
            return false;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            int currentBreadthSize = pendingNodes.size();
            for (int i = 1; i <= currentBreadthSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();

                if (isPerfectSubTree(current, subRoot))
                    return true;

                if (current->left != NULL)
                    pendingNodes.push(current->left);

                if (current->right != NULL)
                    pendingNodes.push(current->right);
            }
        }
        return false;
    }
};