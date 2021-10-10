// https://leetcode.com/problems/binary-tree-right-side-view/
#include <iostream>
#include <deque>
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> rightSideValues;
        if (root == NULL)
            return rightSideValues;

        deque<TreeNode *> pendingNodes;
        pendingNodes.push_back(root);

        while (!pendingNodes.empty())
        {
            int currentLevelSize = pendingNodes.size();
            rightSideValues.push_back(pendingNodes.back()->val);
            for (int i = 1; i <= currentLevelSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop_front();

                if (current->left)
                    pendingNodes.push_back(current->left);
                if (current->right)
                    pendingNodes.push_back(current->right);
            }
        }
        return rightSideValues;
    }
};