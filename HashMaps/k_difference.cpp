#include <iostream>
#include <unordered_map>
using namespace std;

int k_difference(int *arr, int size, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
        if (map.count(arr[i]) > 0)
        {
            map[arr[i]]++;
        }
        else
        {
            map[arr[i]] = 1;
        }
    }
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        int diff = arr[i] - k;
        if (map.count(diff) > 0)
        {
            total = total + (map[diff] * map[arr[i]]);
        }

        diff = k + arr[i];
        if (map.count(diff) > 0)
        {
            total = total + (map[diff] * map[arr[i]]);
        }
        map[arr[i]] = 0;
    }
    return total;
}
int main()
{
    int arr[] = {5, 1, 2, 4, 4};
    int size = 5;
    cout << k_difference(arr, size, 3);
}