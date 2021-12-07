/*
/*


Chapter Assignment
Problem Statement: Print Subset Sum to K
Problem Level: HARD
Problem Description:
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output:
3 3
5 1


*/

*/

#include <iostream>
using namespace std;

void printSubsetsSumtoK(int a[], int n, int out[], int m, int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << out[i] << "  ";
            }
            cout << endl;
            return;
        }
        else
        {
            return;
        }
    }
    printSubsetsSumtoK(a + 1, n - 1, out, m, k);
    out[m] = a[0];
    printSubsetsSumtoK(a + 1, n - 1, out, m + 1, k - a[0]);
}

int main()
{
    int ar[] = {3, 6, 2, 1, 4}, out[10];
    printSubsetsSumtoK(ar, 5, out, 0, 6);
}