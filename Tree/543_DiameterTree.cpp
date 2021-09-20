// https://leetcode.com/problems/diameter-of-binary-tree/
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
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 0;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
    }
};

// better form to minimise repetative calculation
class Solution
{
public:
    pair<int, int> getHeightDiameter(TreeNode *root, pair<int, int> heightDiameter)
    {
        if (root == NULL)
        {
            pair<int, int> answer;
            answer.first = 0;
            answer.second = 0;
            return answer;
        }
        pair<int, int> leftHeightDiameter = getHeightDiameter(root->left, heightDiameter);
        pair<int, int> rightHeightDiameter = getHeightDiameter(root->right, heightDiameter);
        int heightOption = leftHeightDiameter.first + rightHeightDiameter.first;
        int diameterOption = max(leftHeightDiameter.second, rightHeightDiameter.second);

        pair<int, int> answerHeightDiameter;
        answerHeightDiameter.first = 1 + max(leftHeightDiameter.first, rightHeightDiameter.first);
        answerHeightDiameter.second = max(heightOption, diameterOption);

        return answerHeightDiameter;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        pair<int, int> heightDiameter;
        heightDiameter.first = 0;
        heightDiameter.second = 0;
        return getHeightDiameter(root, heightDiameter).second;
    }
};