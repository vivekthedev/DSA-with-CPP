#include <iostream>
#include <unordered_map>
using namespace std;

int maximum_occurence(int *a, int size)
{
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
        if (map.count(a[i]) > 0)
        {
            map[a[i]] += 1;
            continue;
        }
        map[a[i]] = 0;
    }
    auto i = map.begin();
    int max = 0, num = i->first;
    for (auto i : map)
    {
        if (max < i.second)
        {
            max = i.second;
            num = i.first;
        }
    }
    return num;
}
int main()
{
    // int a[] = {2, 12, 2, 11, 12, 2, 1, 2, 2, 11, 12, 2, 6};
    int a[] = {1, 4, 5};
    int size = 3;
    // int size = 13;
    cout << maximum_occurence(a, size);
}