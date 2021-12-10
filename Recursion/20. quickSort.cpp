/*
Problem Statement: Quick Sort
Problem Level: MEDIUM
Problem Description:
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.
<br>
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
1 5 2 7 3

Sample Output 2 :
1 2 3 5 7

*/

#include <iostream>
using namespace std;

int partition(int a[], int start, int end)
{
    int pivot = a[end], index = start, i, temp;
    for (i = start; i < end; i++)
    {
        if (a[i] < pivot)
        {
            temp = a[i];
            a[i] = a[index];
            a[index] = temp;
            index++;
        }
    }
    temp = a[end];
    a[end] = a[index];
    a[index] = temp;
    return index;
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int index = partition(a, start, end);
        quickSort(a, start, index - 1);
        quickSort(a, index + 1, end);
    }
}

int main()
{
    int a[10] = {12, 56, 11, 22, 36};
    quickSort(a, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << " " << a[i];
    }

    return 0;
}