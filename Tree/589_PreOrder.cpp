// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
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
    void getPreOrder(Node *root, vector<int> &preOrder)
    {
        if (root == NULL)
            return;

        preOrder.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
            getPreOrder(root->children[i], preOrder);
    }
    vector<int> preorder(Node *root)
    {
        vector<int> answer;
        getPreOrder(root, answer);
        return answer;
    }
};