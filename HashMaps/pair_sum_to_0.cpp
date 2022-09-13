#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int pair_to_sum_zero(int *a, int size)
{
    int output = 0;
    unordered_map<int, int> map;
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
        {
            map[a[i]] += 1;
        }
        else
        {
            v.push_back(-a[i]);
        }
    }
    for (auto i : v)
    {
        if (map.count(i) > 0)
        {
            output += map[i];
        }
    }

    return output;
}
int main()
{
    int a[] = {2, 1, -2, 2, 3};
    int size = 5;
    cout << pair_to_sum_zero(a, size);
}