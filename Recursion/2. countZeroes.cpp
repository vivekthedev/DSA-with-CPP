/*
Chapter Assignment
Problem Statement: Count Zeros
Problem Level: EASY
Problem Description:
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer N

Output Format :
Number of zeros in N

Constraints :
0 <= N <= 10^9

Sample Input 1 :
10204

Sample Output 1 :
2

Sample Input 2 :
708000

Sample Output 2 :
4


*/

#include <iostream>
using namespace std;

int countZeroes(int num, int n)
{

    int r = num % 10;
    if (r == 0)
    {
        n++;
    }

    if (num == 0)
    {
        return n;
    }

    return countZeroes(num / 10, n);
}

int main()
{
    int num = 0, n = 0;
    cout << countZeroes(num, n);
}