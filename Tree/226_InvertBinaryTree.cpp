// https://leetcode.com/problems/invert-binary-tree/
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
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return nullptr;

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);

        return root;
    }
};

// using bfs
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return nullptr;

        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode *current = pendingNodes.front();
            pendingNodes.pop();

            TreeNode *currentLeftCopy = current->left;
            current->left = current->right;
            current->right = currentLeftCopy;

            if (current->left != NULL)
                pendingNodes.push(current->left);

            if (current->right != NULL)
                pendingNodes.push(current->right);
        }

        return root;
    }
};