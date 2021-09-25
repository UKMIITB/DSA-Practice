// https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> averageValues;
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            int currentSize = pendingNodes.size();
            double currentSum = 0;
            for (int i = 1; i <= currentSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();
                currentSum = currentSum + current->val;

                if (current->left)
                    pendingNodes.push(current->left);

                if (current->right)
                    pendingNodes.push(current->right);
            }
            averageValues.push_back(currentSum / currentSize);
        }
        return averageValues;
    }
};