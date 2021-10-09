// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// *** Very good question ***
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// This is not going to work because in dfs further right nodes wouldn't be conneted
class Solution
{
public:
    void connectToRight(Node *root, Node *prev)
    {
        if (root == NULL)
            return;

        while (prev != NULL)
        {
            if (prev->left != NULL && prev->left != root)
            {
                root->next = prev->left;
                break;
            }
            else if (prev->right != NULL && prev->right != root)
            {
                root->next = prev->right;
                break;
            }
            else
                prev = prev->next;
        }

        connectToRight(root->left, root);
        connectToRight(root->right, root->next);
    }

    Node *connect(Node *root)
    {
        connectToRight(root, NULL);
        return root;
    }
};

class Solution
{
public:
    Node *findNext(Node *root)
    {
        if (root == NULL)
            return NULL;

        if (root->left)
            return root->left;
        if (root->right)
            return root->right;
        return findNext(root->next);
    }

    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;

        if (root->left != NULL)
            root->left->next = root->right != NULL ? root->right : findNext(root->next);

        if (root->right != NULL)
            root->right->next = findNext(root->next);

        connect(root->right);
        connect(root->left);

        return root;
    }
};