// https://leetcode.com/problems/binary-search-tree-iterator/
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

class BSTIterator
{
private:
    vector<int> inOrderValues;
    int currentIndex;

    void getInorderValues(TreeNode *root)
    {
        if (root == NULL)
            return;
        getInorderValues(root->left);
        this->inOrderValues.push_back(root->val);
        getInorderValues(root->right);
    }

public:
    BSTIterator(TreeNode *root)
    {
        currentIndex = -1;
        getInorderValues(root);
    }

    int next()
    {
        currentIndex++;
        return this->inOrderValues[currentIndex];
    }

    bool hasNext()
    {
        if (currentIndex + 1 >= this->inOrderValues.size())
            return false;
        else
            return true;
    }
};