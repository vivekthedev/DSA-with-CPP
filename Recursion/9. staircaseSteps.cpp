/*

Chapter Assignment
Problem Statement: Staircase
Problem Level: EASY
Problem Description:
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :
Integer N

Output Format :
Integer W

Constraints :
1 <= N <= 30

Sample Input 1 :
4

Sample Output 1 :
7

Sample Input 2 :
5

Sample Output 2 :
13
*/

#include <iostream>
using namespace std;

int possibleWays(int remainingSteps, int stepsTaken = 0)
{
    if (remainingSteps == 0)
    {
        return stepsTaken + 1;
    }

    else if (remainingSteps > 0)
    {
        int way1 = possibleWays(remainingSteps - 1, stepsTaken);
        int way2 = possibleWays(remainingSteps - 2, stepsTaken);
        int way3 = possibleWays(remainingSteps - 3, stepsTaken);
        return way1 + way2 + way3;
    }
}

int main()
{

    cout << possibleWays(4);
    return 0;
}