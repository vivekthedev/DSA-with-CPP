/*
Problem Statement: Merge Sort
Problem Level: MEDIUM
Problem Description:
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
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
2 1 5 2 3

Sample Output 2 :
1 2 2 3 5
*/
#include <iostream>
using namespace std;
void mergeArr(int arr[], int start, int mid, int end)
{
    int sCopy = start;
    int m = mid + 1, i = 0;
    int a[50];
    while (start <= mid && m <= end)
    {
        if (arr[start] <= arr[m])
        {
            a[i++] = arr[start++];
        }
        else
        {
            a[i++] = arr[m++];
        }
    }
    while (m <= end)
    {
        a[i++] = arr[m++];
    }
    while (start <= mid)
    {
        a[i++] = arr[start++];
    }
    for (int j = 0; j < i; j++)
    {
        arr[sCopy++] = a[j];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        mergeArr(arr, start, mid, end);
        for (int i = 0; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int a[] = {22, 23, 112, 2, 45, 78};
    mergeSort(a, 0, 5);

    for (int i = 0; i <= 5; i++)
    {
        cout << a[i] << " ";
    }
}