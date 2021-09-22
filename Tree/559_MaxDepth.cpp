// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == NULL)
            return 0;

        int maxDepthOfChildren = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            maxDepthOfChildren = max(maxDepthOfChildren, maxDepth(root->children[i]));
        }
        return 1 + maxDepthOfChildren;
    }
};