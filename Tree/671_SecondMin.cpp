// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
#include <iostream>
#include <set>
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
    int findSecondMinimumValue(TreeNode *root)
    {
        queue<TreeNode *> pendingNodes;
        set<int> values;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            int currentSize = pendingNodes.size();
            for (int i = 1; i <= currentSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();
                values.insert(current->val);

                if (current->left)
                    pendingNodes.push(current->left);

                if (current->right)
                    pendingNodes.push(current->right);
            }
        }

        if (values.size() == 1)
            return -1;

        int index = 0;
        for (auto val : values)
        {
            if (index == 1)
                return val;
            index++;
        }
        return -1;
    }
};