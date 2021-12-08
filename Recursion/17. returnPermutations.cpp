/*

Chapter Assignment
Problem Statement: Return Permutations - String
Problem Level: HARD
Problem Description:
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba
*/
#include <iostream>
using namespace std;

int returnPermutaions(string input, string out)
{
    if (input.length() == 0)
    {
        cout << out << "\n";
    }
    for (int i = 0; i < input.length(); i++)
    {
        string inCopy = input;
        if (input.length() > 1)
        {

            int temp = inCopy[0];
            inCopy[0] = inCopy[i];
            inCopy[i] = temp;
        }
        returnPermutaions(inCopy.substr(1), out + inCopy[0]);
    }
}
int main()
{

    returnPermutaions("adg", "");
}