/*
Problem Statement: Rotate array
Problem Level: EASY
Problem Description:
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
Note:
Change in the input array/list itself. You don't need to return or print the elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains the value of 'D' by which the array/list needs to be rotated.

Output Format :
For each test case, print the rotated array/list in a row separated by a single space.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N
Time Limit: 1 sec

Sample Input 1:
1
7
0 1 2 3 4 5 6
1 2 3 4 5 6 7
2

Sample Output 1:
3 4 5 6 7 1 2

Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2

Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2

*/

#include <iostream>
using namespace std;

// Helper Functions
void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void reverse(int start, int end, int a[])
{
    while (start < end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

// Solution Functions
void rotateArrayApproach_A(int a[], int size, int d)
{
    int temp;
    for (int i = 0; i < d; i++)
    {
        temp = a[0];
        for (int j = 1; j < size; j++)
        {
            a[j - 1] = a[j];
        }
        a[size - 1] = temp;
    }
}

void rotateArrayApproach_B(int a[], int size, int d)
{
    int *ac = new int[d];
    for (int i = 0; i < d; i++)
    {
        ac[i] = a[i];
    }
    for (int i = d; i < size; i++)
    {
        a[i - d] = a[i];
    }
    for (int i = 0; i < d; i++)
    {
        a[(size - d) + i] = ac[i];
    }
}

void rotateArrayApproach_C(int a[], int size, int d)
{
    int start = 0, end = size - 1;
    reverse(start, end, a);
    start = 0;
    end = (size - 1) - d;
    reverse(start, end, a);
    start = size - d;
    end = size - 1;
    reverse(start, end, a);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7;
    int d = 1;
    display(a, size);
    rotateArrayApproach_A(a, size, d);
    display(a, size);
    int a2[] = {1, 2, 3, 4, 5, 6, 7};
    rotateArrayApproach_B(a2, size, d);
    display(a, size);
    int a3[] = {1, 2, 3, 4, 5, 6, 7};
    display(a, size);
    return 0;
}