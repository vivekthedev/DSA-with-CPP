#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int longest_sequence(int *arr, int size)
{

    unordered_map<int, bool> map;
    int prev = 0, max_length = 0;
    int start;
    for (int i = 0; i < size; i++)
    {
        map[arr[i]] = true;
    }

    for (int i = 0; i < size; i++)
    {
        if (map[arr[i]])
        {

            max_length++;
            int curr = arr[i] - 1;
            while (map.count(curr) > 0)
            {
                max_length++;
                start = curr;
                map[curr] = false;
                curr--;
            }
            curr = arr[i] + 1;
            while (map.count(curr) > 0)
            {

                max_length++;
                map[curr] = false;
                curr++;
            }
        }
        if (prev < max_length)
        {
            prev = max_length;
        }
        max_length = 0;
    }
    return prev;
}

int main()
{
    int arr[] = {2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    int size = 13;
    cout << longest_sequence(arr, size);
}