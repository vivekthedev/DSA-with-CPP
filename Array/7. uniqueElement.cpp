#include <iostream>
using namespace std;

int uniqueElement(int arr[], int size)
{
    int num, flag = 0;
    for (int i = 0; i < size; i++)
    {
        num = arr[i];
        for (int j = 0; j < size; j++)
        {
            if (j == i)
            {
                continue;
            }
            if (num == arr[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return num;
        }
        flag = 0;
    }
}

int main()
{
    int arr[] = {1, 3, 1, 3, 6, 6, 7, 10, 10};
    int size = 9;
    cout << uniqueElement(arr, size);
    return 0;
}