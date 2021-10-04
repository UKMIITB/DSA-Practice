// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> finalAnswer;
        if (root == NULL)
            return finalAnswer;
        queue<TreeNode *> pendingNodes;
        bool isReverse = false;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            vector<int> levelVal;
            int currentSize = pendingNodes.size();
            for (int i = 1; i <= currentSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();

                levelVal.push_back(current->val);

                if (current->left)
                    pendingNodes.push(current->left);

                if (current->right)
                    pendingNodes.push(current->right);
            }
            if (isReverse)
                reverse(levelVal.begin(), levelVal.end());
            isReverse = !isReverse;

            finalAnswer.push_back(levelVal);
        }
        return finalAnswer;
    }
};