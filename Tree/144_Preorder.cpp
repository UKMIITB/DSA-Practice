// https://leetcode.com/problems/binary-tree-preorder-traversal/
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> getPreOrder(TreeNode *root, vector<int> &preOrder)
    {
        if (root == NULL)
            return preOrder;

        preOrder.push_back(root->val);
        getPreOrder(root->left, preOrder);
        getPreOrder(root->right, preOrder);

        return preOrder;
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preOrder;
        return getPreOrder(root, preOrder);
    }
};

// dfs without recursion

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preOrder;
        if (root == NULL)
            return preOrder;

        stack<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode *current = pendingNodes.top();
            pendingNodes.pop();
            preOrder.push_back(current->val);

            if (current->right != NULL)
                pendingNodes.push(current->right);

            if (current->left != NULL)
                pendingNodes.push(current->left);
        }

        return preOrder;
    }
};