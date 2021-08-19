// https://leetcode.com/problems/implement-stack-using-queues/
#include <iostream>
#include <queue>
using namespace std;
class MyStack
{
    queue<int> q1;
    queue<int> temp;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int val = q1.back();

        while (q1.size() != 1)
        {
            temp.push(q1.front());
            q1.pop();
        }
        q1.pop(); // removing last value

        while (!temp.empty())
        {
            q1.push(temp.front());
            temp.pop();
        }

        return val;
    }

    /** Get the top element. */
    int top()
    {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};

// one queue solution
class MyStack
{
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int size = q.size();
        q.push(x);

        // now bring the last element to top
        for (int i = 1; i <= size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    /** Get the top element. */
    int top()
    {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(5);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
}