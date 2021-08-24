// https://leetcode.com/problems/dota2-senate/
#include <iostream>
#include <queue>
using namespace std;

string predictPartyVictory(string senate)
{
    int radiantToDie = 0;
    int direToDie = 0;
    int radiantAlive = 0;
    int direAlive = 0;
    vector<char> mVector;

    for (int i = 0; i < senate.size(); i++)
    {
        if (senate.at(i) == 'R')
            radiantAlive++;
        else
            direAlive++;

        mVector.push_back(senate.at(i));
    }

    int index = 0;

    while (radiantAlive > 0 && direAlive > 0)
    {
        if (index > senate.size() - 1) // start from first
            index = 0;

        if (mVector.at(index) == 'X') // this is out of game
        {
            index++;
            continue;
        }

        if (mVector.at(index) == 'R')
        {
            if (radiantToDie > 0)
            {
                mVector.at(index) = 'X'; // this radiant is dead
                radiantAlive--;
                radiantToDie--;
            }
            else
            {
                direToDie++; // mark target for upcoming nearest dire
            }
        }
        else // current is dire
        {
            if (direToDie > 0)
            {
                mVector.at(index) = 'X'; // this dire is dead
                direAlive--;
                direToDie--;
            }
            else
            {
                radiantToDie++; // mark target for upcoming nearest radiant
            }
        }
        index++;
    }

    if (radiantAlive > 0)
        return "Radiant";
    else
        return "Dire";
}

int main()
{
    string input = "DRRDRDRDRDDRDRDR";
    string output = predictPartyVictory(input);
    cout << output;
    return 0;
}