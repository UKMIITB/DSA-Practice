// https://leetcode.com/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode *rootLeft, TreeNode *rootRight)
    {
        if (rootLeft == NULL && rootRight == NULL)
            return true;

        if (rootLeft == NULL || rootRight == NULL)
            return false;

        return (rootLeft->val == rootRight->val) && isSymmetric(rootLeft->left, rootRight->right) && isSymmetric(rootLeft->right, rootRight->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;

        if (root->left == NULL && root->right == NULL)
            return true;

        return isSymmetric(root->left, root->right);
    }
};

// iterative solution, get level wise values & check if it symmetric or not using palindrome check

bool isPalindrome(vector<int> &v)
{
    int left = 0;
    int right = v.size() - 1;
    while (left <= right)
    {
        if (v[left++] == v[right--])
            continue;
        else
            return false;
    }
    return true;
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->left == NULL || root->right == NULL)
        return false;

    queue<TreeNode *> pendingNodes;
    vector<int> levelWiseValues;

    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        int totalNodeAtCurrentLevel = pendingNodes.size();
        for (int i = 1; i <= totalNodeAtCurrentLevel; i++)
        {
            TreeNode *currentNode = pendingNodes.front();
            pendingNodes.pop();

            if (currentNode == NULL)
                levelWiseValues.push_back(-101); // -101 is out of range value
            else
            {
                levelWiseValues.push_back(currentNode->val);
                pendingNodes.push(currentNode->left);
                pendingNodes.push(currentNode->right);
            }
        }

        if (!isPalindrome(levelWiseValues))
            return false;
        else
            levelWiseValues.clear();
    }
    return true;
}