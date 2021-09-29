// https://leetcode.com/problems/unique-binary-search-trees-ii/
// *** Very good question ***
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
    vector<TreeNode *> getBSTTree(int left, int right)
    {
        vector<TreeNode *> answer;
        if (left > right)
        {
            answer.push_back(nullptr);
            return answer;
        }
        else if (left == right)
        {
            answer.push_back(new TreeNode(left));
            return answer;
        }
        else
        {
            for (int i = left; i <= right; i++)
            {
                vector<TreeNode *> leftBST = getBSTTree(left, i - 1);
                vector<TreeNode *> rightBST = getBSTTree(i + 1, right);

                for (int l = 0; l < leftBST.size(); l++)
                {
                    for (int r = 0; r < rightBST.size(); r++)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = leftBST[l];
                        root->right = rightBST[r];
                        answer.push_back(root);
                    }
                }
            }
            return answer;
        }
    }

    vector<TreeNode *> generateTrees(int n)
    {
        return getBSTTree(1, n);
    }
};