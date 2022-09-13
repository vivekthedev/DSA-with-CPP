#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> remove_duplicates(int *a, int size)
{
    vector<int> nums;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true;
        nums.push_back(a[i]);
    }
    return nums;
}
int main()
{
    int a[] = {1, 2, 3, 2, 3, 4, 3, 4, 5};
    vector<int> v = remove_duplicates(a, 9);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
}