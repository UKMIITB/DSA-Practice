// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inOrder;
        if (root == NULL)
            return inOrder;

        vector<int> left = inorderTraversal(root->left);
        for (int i = 0; i < left.size(); i++)
            inOrder.push_back(left[i]);

        inOrder.push_back(root->val);

        vector<int> right = inorderTraversal(root->right);
        for (int i = 0; i < right.size(); i++)
            inOrder.push_back(right[i]);

        return inOrder;
    }
};

// iterative solution
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> pendingNodes;
        TreeNode *current = root;
        vector<int> inOrder;

        if (root == NULL)
            return inOrder;

        while (!pendingNodes.empty() || current != NULL)
        {
            if (current != NULL)
            {
                pendingNodes.push(current);
                current = current->left;
            }
            else
            {
                inOrder.push_back(pendingNodes.top()->val);
                current = pendingNodes.top()->right;
                pendingNodes.pop();
            }
        }

        return inOrder;
    }
};