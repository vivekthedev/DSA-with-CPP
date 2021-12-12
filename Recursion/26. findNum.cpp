/*
Check if a number is present in the array or not using recursion
*/
#include <iostream>
using namespace std;

bool findNum(int a[], int size, int num)
{
    if (a[0] == num)
        return true;
    if (size == 1 || size <= 0)
        return false;
    return findNum(a + 1, size - 1, num);
}

int main()
{
    int a[] = {2, 51, 43, 134, 633, 3};
    findNum(a, 6, 135) ? cout << "true" : cout << "false";
}