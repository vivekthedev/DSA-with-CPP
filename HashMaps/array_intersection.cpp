#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> array_intersection(int *a1, int *a2, int s1, int s2)
{
    vector<int> output;
    unordered_map<int, int> map;
    for (int i = 0; i < s1; i++)
    {
        if (map.count(a1[i]) > 0)
        {
            map[a1[i]] += 1;
            continue;
        }
        map[a1[i]] = 1;
    }
    for (int i = 0; i < s2; i++)
    {
        if (map.count(a2[i]) > 0)
        {
            output.push_back(a2[i]);
            map[a2[i]] -= 1;
        }
    }
    return output;
}

int main()
{
    int a1[] = {2, 6, 8, 5, 4, 3};
    int a2[] = {2, 3, 4, 7};
    int s1 = 6;
    int s2 = 4;
    vector<int> v = array_intersection(a1, a2, s1, s2);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}