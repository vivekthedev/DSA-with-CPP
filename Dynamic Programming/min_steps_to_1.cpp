/*

Coding Problem
Problem Statement: Min Steps to one
Problem Level: EASY
Problem Description:
Given a positive integer 'n',  find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).

Write brute-force recursive solution for this.
Input format :
The first and the only line of input contains an integer value, 'n'.

Output format :
Print the minimum number of steps.

Constraints :
1 <= n <= 200

Time Limit: 1 sec

Sample Input  1 :
4

Sample Output  1 :
2

Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1

Sample Input  2 :
7

Sample Output  2 :
3

Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2
Step 3 : n = 2 / 2 = 1

*/

#include <iostream>
#include <limits.h>
using namespace std;
int min_steps_brute_force(int num)
{
    if (num == 1)
        return 0;
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (num % 3 == 0)
    {
        a = min_steps_brute_force(num / 3);
    }
    if (num % 2 == 0)
    {
        b = min_steps_brute_force(num / 2);
    }
    c = min_steps_brute_force(num - 1);

    int min;
    if (a < b && a < c)
        min = a;
    else if (b < a && b < c)
        min = b;
    else
        min = c;

    return min + 1;
}

int min_steps_memoization_helper(int num, int *arr)
{
    if (num == 1)
        return 0;
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (num % 3 == 0)
    {
        if (arr[num / 3] == -1)
        {
            a = min_steps_memoization_helper(num / 3, arr);
            arr[num / 3] = a;
        }
        else
            a = arr[num / 3];
    }
    if (num % 2 == 0)
    {
        if (arr[num / 2] == -1)
        {
            b = min_steps_memoization_helper(num / 2, arr);
            arr[num / 2] = b;
        }
        else
            b = arr[num / 2];
    }
    if (arr[num - 1] == -1)
    {
        c = min_steps_memoization_helper(num - 1, arr);
        arr[num - 1] = c;
    }
    else
        c = arr[num - 1];

    int min;
    if (a < b && a < c)
        min = a;
    else if (b < a && b < c)
        min = b;
    else
        min = c;

    return min + 1;
}

int min_steps_memoization(int num)
{
    int *arr = new int[num + 1];
    for (int i = 0; i < num + 1; i++)
    {
        arr[i] = -1;
    }
    return min_steps_memoization_helper(num, arr);
}
int min_steps_dp(int num)
{
    int *arr = new int[num + 1];
    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i < num + 1; i++)
    {
        int a = arr[i - 1];
        int b = i % 2 == 0 ? arr[i / 2] : INT_MAX;
        int c = i % 3 == 0 ? arr[i / 3] : INT_MAX;
        int min = a;
        if (b < a && b < c)
            min = b;

        if (c < a && c < b)
            min = c;
        arr[i] = min + 1;
    }
    return arr[num];
}

int main()
{
    // cout << min_steps_brute_force(9) << endl;
    // cout << min_steps_memoization(11) << endl;
    cout << min_steps_dp(11) << endl;
}