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