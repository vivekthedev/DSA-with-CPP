/*
Chapter TEST
Problem Statement: Does s contain t ?
Problem Level: EASY
Problem Description:
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
true or false

Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding

Sample Output 1 :
true

Sample Input 2 :
abcde
aeb

Sample Output 2 :
false


*/

#include <iostream>
using namespace std;

bool doesContainText(string s, string t)
{
    if (t.empty())
    {
        return true;
    }
    else if (s.empty() && !t.empty())
    {
        return false;
    }
    else
    {
        bool out;
        if (s[0] == t[0])
        {
            out = doesContainText(s.substr(1), t.substr(1));
        }
        else
        {
            out = doesContainText(s.substr(1), t);
        }
        return out;
    }
}

int main()
{
    string s = "abcde";
    string t = "aeb";
    cout << doesContainText(s, t);
}