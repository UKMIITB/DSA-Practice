// https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL)
            return 1 + minDepth(root->right);

        if (root->right == NULL)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// using bfs algorithm
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<TreeNode *> pendingNode;

        int height = 0;
        pendingNode.push(root);

        while (!pendingNode.empty())
        {
            height++;
            int breadthNodes = pendingNode.size();
            for (int i = 1; i <= breadthNodes; i++)
            {
                TreeNode *current = pendingNode.front();
                pendingNode.pop();

                if (current->left == NULL && current->right == NULL) // its a leaf node
                    return height;
                else
                {
                    if (current->left != NULL)
                        pendingNode.push(current->left);

                    if (current->right != NULL)
                        pendingNode.push(current->right);
                }
            }
        }

        return -1; // this will never reach here, as before this it will reach leaf node
    }
};