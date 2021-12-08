/*

Chapter Assignment
Problem Statement: Print all Codes - String
Problem Level: HARD
Problem Description:
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void printCodes(string str, string out)
{
    if (str.empty())
    {
        cout << out << endl;
        return;
    }
    // out = out + str[0];
    char one = char(atoi(str.substr(0, 1).c_str()) + 96);
    printCodes(str.substr(1), out + one);
    if (str.length() >= 2)
    {
        char two = char(atoi(str.substr(0, 2).c_str()) + 96);
        printCodes(str.substr(2), out + two);
    }
}

int main()
{
    string input = "1123";
    printCodes(input, "");
}