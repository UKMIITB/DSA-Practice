// https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> getPostOrder(TreeNode *root, vector<int> &postOrder)
    {
        if (root == NULL)
            return postOrder;
        getPostOrder(root->left, postOrder);
        getPostOrder(root->right, postOrder);
        postOrder.push_back(root->val);

        return postOrder;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postOrder;
        return getPostOrder(root, postOrder);
    }
};

// iterative solution
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root) // iterate the tree in preorder but little different: root --> right --> left . Than reverse it
    {
        vector<int> postOrder;
        if (root == NULL)
            return postOrder;

        stack<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode *current = pendingNodes.top();
            pendingNodes.pop();
            postOrder.push_back(current->val);

            if (current->left != NULL)
                pendingNodes.push(current->left);

            if (current->right != NULL)
                pendingNodes.push(current->right);
        }

        reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }
};