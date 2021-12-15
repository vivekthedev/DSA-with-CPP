#include <iostream>
using namespace std;

int checkArrayRotationLinearApproach(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return i + 1;
        }
    }
}

int main()
{
    int arr[] = {5, 6, 1, 2, 3, 4};
    int size = 6;
    cout << checkArrayRotationLinearApproach(arr, size);
    return 0;
}