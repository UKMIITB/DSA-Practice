// https://leetcode.com/problems/implement-queue-using-stacks/
#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
    stack<int> stack1;
    stack<int> temp;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        return customPopTop(true);
    }

    /** Get the front element. */
    int peek()
    {
        return customPopTop(false);
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stack1.empty();
    }

private:
    int customPopTop(bool isPop)
    {
        while (!stack1.empty())
        {
            temp.push(stack1.top());
            stack1.pop();
        }

        int val = temp.top();

        if (isPop)
            temp.pop();

        while (!temp.empty())
        {
            stack1.push(temp.top());
            temp.pop();
        }

        return val;
    }
};

class MyQueue
{
    stack<int> input;
    stack<int> output;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        peek();
        int val = output.top();
        output.pop();
        return val;
    }

    /** Get the front element. */
    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return input.empty() && output.empty();
    }
};