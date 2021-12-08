/*

Chapter Assignment
Problem Statement: Return all codes - String
Problem Level: HARD
Problem Description:
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string

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

int returnCodes(string str, string out[], string c)
{
    if (c.empty())
    {
        return 1;
    }
    int s1 = 0, s2 = 0;
    string one = c.substr(0, 1), two = c.substr(0, 2);
    s1 = returnCodes(one, out, c.substr(1));
    for (int i = 0; i < s1; i++)
    {
        // cout << char(atoi(one.c_str()) + 96) + out[i];
        out[i] = char(atoi(one.c_str()) + 96) + out[i];
    }

    if (c.length() >= 2)
    {
        s2 = returnCodes(two, out, c.substr(2));
        for (int i = s1; i < s1 + s2; i++)
        {
            // cout << char(atoi(two.c_str()) + 96) + out[i] << i << endl;
            out[i] = char(atoi(two.c_str()) + 96) + out[i];
        }
    }

    return s1 + s2;
}

int main()
{
    string a = "1123";
    string out[10];
    // out[0] = "hellow";
    // cout << a;
    // cout << char(atoi(a.c_str()) + 96);
    int size = returnCodes(a, out, a);

    for (int i = 0; i < size; i++)
    {
        cout << out[i] << endl;
    }
    // out[0] = char(atoi(a.c_str()) + 96) + out[0];
    // cout << out[0];
}