#include <iostream>
using namespace std;

void intersectionLinearApproach(int a[], int b[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                cout << a[i] << " ";
                b[j] = -1;
            }
        }
    }
}

void sortedApproach(int a[], int b[], int m, int n)
{

    int i = 0, j = 0;
    // cout << "sorted";
    while (i < m && j < n)
    {
        // cout << "inloop" << endl;
        // cout << a[i] << "  " << b[j] << endl;
        if (a[i] == b[j])
        {
            cout << b[j] << " ";
            i++;
            j++;
        }
        if (a[i] < b[j])
        {
            i++;
        }

        else if (a[i] > b[j])
        {
            j++;
        }
    }
}
int main()
{
    int a[] = {0, 1, 2, 4, 5, 6, 9};
    int b[] = {0, 2, 3, 4};
    int m = 7, n = 4;
    // intersectionLinearApproach(a, b, m, n);
    sortedApproach(a, b, m, n);
}