// https://leetcode.com/problems/first-unique-character-in-a-string/
#include <iostream>
#include <unordered_map>
using namespace std;

struct customVal
{
    int count;
    int index;
    customVal(int count, int index)
    {
        this->count = count;
        this->index = index;
    }

    customVal()
    {
        this->count = INT_MAX;
        this->index = INT_MAX;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, customVal> mMap;
        customVal answer;

        for (int i = 0; i < s.size(); i++)
        {
            if (mMap.count(s.at(i)) == 1) // already present in map
            {
                customVal val = mMap[s.at(i)];
                val.count = val.count + 1; // since already present se index is already smaller
                mMap[s.at(i)] = val;
            }
            else
            {
                mMap[s.at(i)] = customVal(1, i);
            }
        }

        unordered_map<char, customVal>::iterator itr = mMap.begin();
        for (; itr != mMap.end(); itr++)
        {
            if (itr->second.count == 1 && itr->second.index < answer.index)
                answer = itr->second;
        }

        if (answer.index == INT_MAX)
            return -1;

        return answer.index;
    }
};

int main()
{
    return 0;
}