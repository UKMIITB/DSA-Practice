// https://leetcode.com/problems/reveal-cards-in-increasing-order/
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());

        deque<int> q;
        q.push_back(deck.back());
        deck.pop_back();

        while (!deck.empty())
        {
            q.push_front(q.back());
            q.pop_back();

            q.push_front(deck.back());
            deck.pop_back();
        }

        vector<int> answer;
        while (!q.empty())
        {
            answer.push_back(q.front());
            q.pop_front();
        }

        return answer;
    }
};