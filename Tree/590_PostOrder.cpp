// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    void getPostOrder(Node *root, vector<int> &postOrder)
    {
        if (root == NULL)
            return;

        for (int i = 0; i < root->children.size(); i++)
            getPostOrder(root->children[i], postOrder);

        postOrder.push_back(root->val);
    }

    vector<int> postorder(Node *root)
    {
        vector<int> answer;
        getPostOrder(root, answer);
        return answer;
    }
};