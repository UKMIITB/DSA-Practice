// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#include <iostream>
#include <unordered_set>
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
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> mSet;
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            int currentSize = pendingNodes.size();
            for (int i = 1; i <= currentSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();

                if (current->left)
                    pendingNodes.push(current->left);

                if (current->right)
                    pendingNodes.push(current->right);

                mSet.insert(current->val);
            }
        }

        for (auto eachVal : mSet)
        {
            if (eachVal != k - eachVal && mSet.count(k - eachVal))
                return true;
        }
        return false;
    }
};