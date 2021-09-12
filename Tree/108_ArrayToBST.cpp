// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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

TreeNode *binaryTreeRoot(vector<int> &nums, int low, int high)
{
    if (low > high)
        return NULL;

    int middle = low + (high - low) / 2;
    TreeNode *root = new TreeNode(nums[middle]);

    TreeNode *leftRoot = binaryTreeRoot(nums, low, middle - 1);
    TreeNode *rightRoot = binaryTreeRoot(nums, middle + 1, high);

    root->left = leftRoot;
    root->right = rightRoot;
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
        return NULL;

    if (nums.size() == 1)
        return new TreeNode(nums[0]);

    return binaryTreeRoot(nums, 0, nums.size() - 1);
}

int main()
{
    return 0;
}