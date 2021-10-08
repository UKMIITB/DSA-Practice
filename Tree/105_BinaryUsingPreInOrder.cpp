// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// *** Important Question ***
#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode *buildTreeHelper(vector<int> &preOrder, vector<int> &inOrder, int &rootIndex, int start, int end, unordered_map<int, int> &mMapInorder)
    {
        if (start > end)
            return NULL;

        int currentRootVal = preOrder[rootIndex];
        int indexOfCurrentRootInInOrder = mMapInorder[currentRootVal];
        rootIndex++;

        TreeNode *root = new TreeNode(currentRootVal);
        root->left = buildTreeHelper(preOrder, inOrder, rootIndex, start, indexOfCurrentRootInInOrder - 1, mMapInorder);
        root->right = buildTreeHelper(preOrder, inOrder, rootIndex, indexOfCurrentRootInInOrder + 1, end, mMapInorder);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mMapInorder;
        for (int i = 0; i < inorder.size(); i++)
        {
            mMapInorder.insert(make_pair(inorder[i], i));
        }
        int rootIndex = 0;
        return buildTreeHelper(preorder, inorder, rootIndex, 0, inorder.size() - 1, mMapInorder);
    }
};