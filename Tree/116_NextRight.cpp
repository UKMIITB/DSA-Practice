// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;

        queue<Node *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            int currentSize = pendingNodes.size();
            for (int i = 1; i <= currentSize; i++)
            {
                Node *current = pendingNodes.front();
                pendingNodes.pop();

                if (i != currentSize)
                    current->next = pendingNodes.front();
                else
                    current->next = NULL;

                if (current->left)
                    pendingNodes.push(current->left);
                if (current->right)
                    pendingNodes.push(current->right);
            }
        }
        return root;
    }
};

// 2nd way using O(1) space complexity
class Solution
{
public:
    void connectToRight(Node *root, Node *prev, bool isRightCall)
    {
        if (root == NULL)
            return;

        if (isRightCall)
        {
            if (prev != NULL && prev->next != NULL && prev->next->left != NULL)
                root->next = prev->next->left;
            else
                root->next = NULL;
        }
        else
        {
            if (prev != NULL && prev->right != NULL)
                root->next = prev->right;
            else
                root->next = NULL;
        }

        connectToRight(root->left, root, false);
        connectToRight(root->right, root, true);
    }

    Node *connect(Node *root)
    {
        connectToRight(root, NULL, false);
        return root;
    }
};