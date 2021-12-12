/*
Find the location of the element in the array using recursion
*/

#include <iostream>
using namespace std;

int findNum(int a[], int size, int num)
{
    if (a[0] == num)
        return 0;
    if (size <= 0)
        return -1;
    return findNum(a + 1, size - 1, num) + 1;
}

int main()
{
    int a[] = {2, 51, 43, 134, 633, 3};
    cout << findNum(a, 6, 312);
}