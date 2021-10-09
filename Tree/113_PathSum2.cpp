// https://leetcode.com/problems/path-sum-ii/
#include <iostream>
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
    vector<int> getPathSum(TreeNode *root, int &targetSum, vector<int> currentPath, int currentPathSum, vector<vector<int>> &allPaths)
    {
        if (root == NULL) // do nothing
            return currentPath;

        if (root->left == NULL && root->right == NULL) // we have reached a leaf
        {
            currentPath.push_back(root->val);
            currentPathSum += root->val;

            if (currentPathSum == targetSum)
                allPaths.push_back(currentPath);

            return currentPath;
        }
        currentPath.push_back(root->val);
        currentPathSum += root->val;
        getPathSum(root->left, targetSum, currentPath, currentPathSum, allPaths);
        getPathSum(root->right, targetSum, currentPath, currentPathSum, allPaths);
        return currentPath;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        int currentPathSum = 0;
        getPathSum(root, targetSum, currentPath, currentPathSum, allPaths);
        return allPaths;
    }
};