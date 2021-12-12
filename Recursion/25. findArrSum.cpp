/*
Find Array sum using recursion
*/

#include <iostream>
using namespace std;

int findSum(int a[], int size)
{
    if (size == 1)
    {
        return a[0];
    }
    else
    {
        return a[size - 1] + findSum(a + 1, size - 1);
    }
}

int main()
{
    int a[] = {21, 34, 123, 12, 2};
}