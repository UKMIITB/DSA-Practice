// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> answer;
        if (root == NULL)
            return answer;

        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            vector<int> levelOrder;
            int levelSize = pendingNodes.size();
            for (int i = 1; i <= levelSize; i++)
            {
                TreeNode *current = pendingNodes.front();
                pendingNodes.pop();

                if (current->left)
                    pendingNodes.push(current->left);
                if (current->right)
                    pendingNodes.push(current->right);

                levelOrder.push_back(current->val);
            }
            answer.push_back(levelOrder);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};