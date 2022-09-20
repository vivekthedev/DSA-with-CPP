/*

Coding Problem
Problem Statement: Minimum Count
Problem Level: MEDIUM
Problem Description:
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1     is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.

Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
12

Sample Output 1 :
3

Explanation of Sample Output 1 :
12 can be represented as :
A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)

B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)

C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :
9

Sample Output 2 :
1

*/

#include <iostream>
#include <vector>
using namespace std;

int minimum_counts_helper(int num, int *arr)
{
    if (arr[num] != -1)
    {
        return arr[num];
    }
    vector<int> output;
    for (int i = 1; i * i <= num; i++)
    {
        output.push_back(minimum_counts_helper(num - (i * i), arr) + 1);
    }
    int min = output[0];
    for (int i = 1; i < output.size(); i++)
    {
        if (output[i] < min)
        {
            min = output[i];
        }
    }
    arr[num] = min;
    return min;
}
int minimum_counts(int num)
{
    int *arr = new int[num + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < num + 1; i++)
    {
        arr[i] = -1;
    }
    int ans = minimum_counts_helper(num, arr);
    return ans;
}
int main()
{
    cout << minimum_counts(12);
}