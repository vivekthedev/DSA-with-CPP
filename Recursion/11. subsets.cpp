/*
Chapter Assignment
Problem Statement: Return subset of an array
Problem Level: HARD
Problem Description:
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Size of array
Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12

*/

#include <iostream>
using namespace std;

int subsets(int a[], int size, int out[][80])
{
    if (size == 0)
    {
        out[0][0] = 0;
        return 1;
    }
    int smallSize = subsets(a + 1, size - 1, out), j;

    for (int i = 0; i < smallSize; i++)
    {
        for (j = 0; j <= out[i][0]; j++)
        {
            out[smallSize + i][j] = out[i][j];
        }
        out[smallSize + i][j] = a[0];
        out[smallSize + i][0]++;
    }
    return 2 * smallSize;
}

int main()
{
    int arr[] = {1, 1, 2, 3};
    int size = 5;
    int out[80][80];
    int osize = subsets(arr, size, out);

    for (int i = 0; i < osize; i++)
    {
        for (int j = 1; j <= out[i][0]; j++)
        {
            cout << out[i][j] << "   ";
        }
        cout << endl;
    }
}