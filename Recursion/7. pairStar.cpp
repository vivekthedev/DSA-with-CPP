/*
Problem Statement: Pair star
Problem Level: MEDIUM
Problem Description:
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello

Sample Output 1:
hel*lo

Sample Input 2 :
aaaa

Sample Output 2 :
a*a*a*a



*/

#include <iostream>
#include <string.h>
using namespace std;

char *pairStar(char str[], int start = 0)
{
    if (str[start] == '\0')
    {
        return str;
    }
    else
    {
        if (str[start] == str[start + 1])
        {
            for (int i = strlen(str); i > start; i--)
            {
                str[i + 1] = str[i];
            }
            str[start + 1] = '*';
        }
        pairStar(str, start + 1);
    }
}

int main()
{
    char str[50] = "hello";
    cout << pairStar(str);
    // cout << str;
}