// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    int getBinaryToDecimalValue(string &currentValues)
    {
        int index = 0;
        int decimalValue = 0;
        for (int i = currentValues.size() - 1; i >= 0; i--)
            decimalValue = decimalValue + (pow(2, index++) * ((int)currentValues[i] - 48));

        return decimalValue;
    }

    void getSumToRoot(TreeNode *root, string currentValues, int &sum)
    {
        if (root == NULL)
        {
            return;
        }
        currentValues += to_string(root->val);
        if (root->left == NULL && root->right == NULL) // reached at leaf, calculate value
        {
            sum += getBinaryToDecimalValue(currentValues);
            return;
        }
        getSumToRoot(root->left, currentValues, sum);
        getSumToRoot(root->right, currentValues, sum);
    }

    int sumRootToLeaf(TreeNode *root)
    {
        string currentValues = "";
        int sum = 0;
        getSumToRoot(root, currentValues, sum);
        return sum;
    }
};