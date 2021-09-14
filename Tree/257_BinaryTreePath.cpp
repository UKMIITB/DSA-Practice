// https://leetcode.com/problems/binary-tree-paths/
#include <iostream>
#include <string>
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
    vector<string> getBinaryTreePaths(TreeNode *root, vector<string> &allPaths, string currentPath)
    {
        if (root->left == NULL && root->right == NULL)
        {
            currentPath += to_string(root->val);
            allPaths.push_back(currentPath);
            return allPaths;
        }
        currentPath += to_string(root->val) + "->";
        if (root->left != NULL)
        {
            getBinaryTreePaths(root->left, allPaths, currentPath);
        }
        if (root->right != NULL)
        {
            getBinaryTreePaths(root->right, allPaths, currentPath);
        }
        return allPaths;
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> allPaths;
        string currentPath = "";
        return getBinaryTreePaths(root, allPaths, currentPath);
    }
};