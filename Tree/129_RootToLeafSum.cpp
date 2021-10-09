// https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    void getAllPathSum(TreeNode *root, string currentPathVal, int &sum)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) // we have reached at leaf node
        {
            currentPathVal += to_string(root->val);
            sum += stoi(currentPathVal);
            return;
        }
        currentPathVal += to_string(root->val);
        getAllPathSum(root->left, currentPathVal, sum);
        getAllPathSum(root->right, currentPathVal, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        string currentPathVal = "";
        getAllPathSum(root, currentPathVal, sum);
        return sum;
    }
};