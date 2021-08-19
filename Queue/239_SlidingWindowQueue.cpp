// https://leetcode.com/problems/sliding-window-maximum/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> answer;

    for (int i = 0; i < nums.size(); i++)
    {
        while (!dq.empty() && dq.back() < nums[i]) // removing all values which are less than current value
            dq.pop_back();

        dq.push_back(nums[i]);

        if (i >= k - 1) // start entering max value in answer
            answer.push_back(dq.front());

        if (i - k + 1 >= 0 && nums[i - k + 1] == dq.front()) // value of trailing sliding window, hence to be removed for next iteration
            dq.pop_front();
    }

    return answer;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(-3);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    vector<int> answer = maxSlidingWindow(v, 3);
    for (int i = 0; i < answer.size(); i++)
        cout << answer.at(i) << endl;

    return 0;
}