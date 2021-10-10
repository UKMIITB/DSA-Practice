// https://leetcode.com/problems/count-complete-tree-nodes/
// *** Good Question ***
#include <iostream>
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
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        TreeNode *leftRoot = root;
        TreeNode *rightRoot = root;
        int leftHeight = 0;
        int rightHeight = 0;
        while (leftRoot)
        {
            leftHeight++;
            leftRoot = leftRoot->left;
        }
        while (rightRoot)
        {
            rightHeight++;
            rightRoot = rightRoot->right;
        }
        if (leftHeight == rightHeight)
            return pow(2, leftHeight) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};