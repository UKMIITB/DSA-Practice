// https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            int currentSize = pendingNodes.size();
            bool isFoundX = false;
            bool isFoundY = false;

            for (int i = 1; i <= currentSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();

                if (current->val == x)
                    isFoundX = true;

                if (current->val == y)
                    isFoundY = true;

                if (current->left && current->right) // check if x and y are children of the same parent
                {
                    if ((current->left->val == x && current->right->val == y) || (current->left->val == y && current->right->val == x))
                        return false;
                }
                if (current->left)
                    pendingNodes.push(current->left);
                if (current->right)
                    pendingNodes.push(current->right);
            }
            if (isFoundX && isFoundY) // both found at the same level
                return true;

            if (isFoundX != isFoundY) // difference of level
                return false;
        }
        return false; // dummy return
    }
};