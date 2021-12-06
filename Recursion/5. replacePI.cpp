/*
Problem Statement: Replace pi (recursive)
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix

Sample Output :
x3.14x

Sample Input 2 :
pipi

Sample Output :
3.143.14

Sample Input 3 :
pip

Sample Output :
3.14p


*/

#include <iostream>
#include <string.h>
using namespace std;

char *replacePI(char *str, int start)
{
    if (str[start] == '\0' || str[start] == '\0')
    {
        return str;
    }
    else
    {
        if (str[start] == 'p' && str[start + 1] == 'i')
        {
            int i = strlen(str) - 1;

            while (i >= (start + 2))
            {
                str[i + 2] + str[i];
                cout << "str[i+2] " << str[i + 2] << "  : "
                     << "str[i] " << str[i] << endl;
                i--;
            }
            cout << endl
                 << str << endl;
            str[start] = '3';
            str[start + 1] = '.';
            str[start + 2] = '1';
            str[start + 3] = '4';
        }
        replacePI(str, start + 1);
    }
}

int main()
{
    char str[] = "xpipix";
    int len = 6;

    cout << replacePI(str, 0);
}