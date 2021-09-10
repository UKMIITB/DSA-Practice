// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    if (accumulate(students.begin(), students.end(), 0) == accumulate(sandwiches.begin(), sandwiches.end(), 0))
        return 0;

    int numOf1EatingStudent = 0;
    for (int i = 0; i < students.size(); i++)
        numOf1EatingStudent += students[i];

    int topSandwichIndex = 0;
    int index = 0;
    int studentsRemainingToEat = students.size();

    while (topSandwichIndex < sandwiches.size())
    {
        if (index >= students.size()) // start from beginning
            index = 0;

        if (students.at(index) == -1) // this student is out of queue
        {
            index++;
            continue;
        }

        if (students.at(index) == sandwiches.at(topSandwichIndex))
        {
            topSandwichIndex++;
            numOf1EatingStudent -= students[index];
            students.at(index) = -1; // this student is now out of queue
            studentsRemainingToEat--;
        }

        index++;

        if ((sandwiches[topSandwichIndex] == 0 && studentsRemainingToEat == numOf1EatingStudent) || (sandwiches[topSandwichIndex] == 1 && studentsRemainingToEat == studentsRemainingToEat - numOf1EatingStudent))
            return studentsRemainingToEat;
    }

    return 0;
}

int main()
{
    return 0;
}