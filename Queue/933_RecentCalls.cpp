// https://leetcode.com/problems/number-of-recent-calls/
#include <iostream>
#include <queue>
using namespace std;

class RecentCounter
{
    queue<int> mQueue;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        mQueue.push(t);

        while (mQueue.front() < mQueue.back() - 3000)
            mQueue.pop();

        return mQueue.size();
    }
};
