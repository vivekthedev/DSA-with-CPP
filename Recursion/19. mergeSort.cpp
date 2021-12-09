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
    // mergeArr(a, 0, 2, 5);

    for (int i = 0; i <= 5; i++)
    {
        cout << a[i] << " ";
    }
}