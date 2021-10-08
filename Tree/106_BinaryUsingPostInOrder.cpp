// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode *buildTreeHelper(vector<int> &postOrder, vector<int> &inOrder, int &rootIndex, int start, int end, unordered_map<int, int> &mMapInorder)
    {
        if (start > end)
            return NULL;

        int currentRootVal = postOrder[rootIndex];
        int indexOfCurrentRootInInOrder = mMapInorder[currentRootVal];
        rootIndex--;

        TreeNode *root = new TreeNode(currentRootVal);
        root->right = buildTreeHelper(postOrder, inOrder, rootIndex, indexOfCurrentRootInInOrder + 1, end, mMapInorder);
        root->left = buildTreeHelper(postOrder, inOrder, rootIndex, start, indexOfCurrentRootInInOrder - 1, mMapInorder);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mMapInorder;
        for (int i = 0; i < inorder.size(); i++)
        {
            mMapInorder[inorder[i]] = i;
        }
        int rootIndex = postorder.size() - 1;
        return buildTreeHelper(postorder, inorder, rootIndex, 0, inorder.size() - 1, mMapInorder);
    }
};