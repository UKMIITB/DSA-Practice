// https://leetcode.com/problems/unique-binary-search-trees/
// *** Very good question ***
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void getNumTrees(int k, vector<int> &values)
    {
        for (int i = 2; i <= k; i++)
        {
            for (int j = 0; j < i; j++)
                values[i] += (values[j] * values[i - j - 1]);
        }
    }

    int numTrees(int n)
    {
        vector<int> values;
        for (int i = 0; i <= n; i++)
            values.push_back(0); // initialising by 0

        values[0] = 1;
        values[1] = 1;
        getNumTrees(n, values);
        return values[n];
    }
};