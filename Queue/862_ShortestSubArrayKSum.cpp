// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int min(int num1, int num2)
{
    if (num1 < num2)
        return num1;
    return num2;
}

int shortestSubarray(vector<int> &nums, int k)
{
    int shortestSubArrayLength = INT_MAX;
    queue<int> mQueue;
    int currQSum = 0;
    int index = 0;

    for (; index < nums.size(); index++)
    {
        mQueue.push(nums.at(index));
        currQSum += nums.at(index);

        if (currQSum >= k)
        {
            index++;
            shortestSubArrayLength = min(shortestSubArrayLength, mQueue.size());
            break;
        }
    }

    while (!mQueue.empty() && ((currQSum - mQueue.front()) >= k)) // keep removing values till sum is just more than k
    {
        currQSum -= mQueue.front();
        mQueue.pop();
    }

    if (index >= nums.size())
    {
        if (currQSum < k)
            return -1;
        else
            return nums.size();
    }

    if (currQSum >= k)
        shortestSubArrayLength = min(shortestSubArrayLength, mQueue.size());

    for (; index < nums.size(); index++)
    {
        int currNum = nums.at(index);

        while (!mQueue.empty() && mQueue.front() < currNum) // keep removing elements till starting values sum is less than new value
        {
            currNum -= mQueue.front();
            currQSum -= mQueue.front();
            mQueue.pop();
        }

        mQueue.push(nums.at(index));
        currQSum += nums.at(index);

        while (!mQueue.empty() && ((currQSum - mQueue.front()) >= k)) // keep removing values till sum is just more than k
        {
            currQSum -= mQueue.front();
            mQueue.pop();
        }

        if (currQSum >= k)
            shortestSubArrayLength = min(shortestSubArrayLength, mQueue.size());
    }

    return shortestSubArrayLength;
}

int main()
{
    return 0;
}