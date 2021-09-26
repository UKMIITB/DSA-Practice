// https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(int &val1, int &val2)
    {
        return val1 < val2;
    }
};

class KthLargest
{
public:
    priority_queue<int, vector<int>, compare> values;
    int k;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto num : nums)
        {
            values.push(num);
        }
    }

    int add(int val)
    {
        values.push(val);
        while (values.size() > k)
        {
            values.pop();
        }
        return values.top();
    }
};