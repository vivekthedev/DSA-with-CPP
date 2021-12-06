/*
Problem Statement: Remove X
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S

Output format :
Modified String

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.

Sample Input 1 :
xaxb

Sample Output 1:
ab

Sample Input 2 :
abc

Sample Output 2:
abc

Sample Input 3 :
xx

Sample Output 3:

*/
#include <iostream>
using namespace std;

char *removeX(char *str, int start)
{
    if (str[start] == '\0')
    {
        return str;
    }
    else
    {
        if (str[start] == 'x')
        {
            int i = start;
            do
            {
                str[i] = str[i + 1];
                i++;
            } while (str[i] != '\0');
        }
        removeX(str, start + 1);
    }
}

int main()
{
    char str[] = "xabxc";
    cout << removeX(str, 0);
}