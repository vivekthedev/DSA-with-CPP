/*
Chapter Assignment
Problem Statement: Check Palindrome (recursive)
Problem Level: MEDIUM
Problem Description:
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar

Sample Output 1:
true

Sample Input 2 :
ninja

Sample Output 2:
false
*/

#include <iostream>
using namespace std;

int checkPalindrome(char n[], int start, int end)
{

    if (n[start] != n[end])
    {

        return 0;
    }
    if (start >= end)
    {
        return 1;
    }
    else
    {

        return checkPalindrome(n, start + 1, end - 1);
    }
}
int main()
{
    char str[] = "malayalam";
    cout << checkPalindrome(str, 0, 8);

    char str2[] = "maama";
    cout << checkPalindrome(str2, 0, 4);
    return 0;
}