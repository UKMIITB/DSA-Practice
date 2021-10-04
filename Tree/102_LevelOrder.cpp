// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> answer;
        if (root == NULL)
            return answer;

        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            vector<int> levelAnswer;
            int currentLevelSize = pendingNodes.size();
            for (int i = 1; i <= currentLevelSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();

                levelAnswer.push_back(current->val);
                if (current->left)
                    pendingNodes.push(current->left);
                if (current->right)
                    pendingNodes.push(current->right);
            }
            answer.push_back(levelAnswer);
        }
        return answer;
    }
};