/*

Problem Statement: Geometric Sum
Problem Level: MEDIUM
Problem Description:
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)

using recursion.
Input format :
Integer k

Output format :
Geometric sum

Constraints :
0 <= k <= 1000

Sample Input 1 :
3

Sample Output 1 :
1.875

Sample Input 2 :
4

Sample Output 2 :
1.93750


*/

#include <iostream>
#include <math.h>
using namespace std;

float geometricSum(int k)
{
    if (k == 0)
    {
        return 1;
    }
    else
    {
        return ((1.0 / pow(2, k)) + geometricSum(k - 1));
    }
}
int main()
{
    int k = 2;
    cout << geometricSum(k);
}