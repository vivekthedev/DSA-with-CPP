#include <iostream>
#include <climits>
using namespace std;

int min_cost_path_brute_force(int input[][3], int m, int n, int i = 0, int j = 0)
{
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    int x = min_cost_path_brute_force(input, m, n, i, j + 1);
    int y = min_cost_path_brute_force(input, m, n, i + 1, j + 1);
    int z = min_cost_path_brute_force(input, m, n, i + 1, j);

    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}

int min_cost_path_memoization(int input[][3], int m, int n, int output[][3], int i = 0, int j = 0)
{
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    if (output[i][j] != -1)
    {
        return output[i][j];
    }
    int x = min_cost_path_brute_force(input, m, n, i, j + 1);
    int y = min_cost_path_brute_force(input, m, n, i + 1, j + 1);
    int z = min_cost_path_brute_force(input, m, n, i + 1, j);

    int ans = min(x, min(y, z)) + input[i][j];
    output[i][j] = ans;
    return ans;
}

int min_cost_path_DP(int input[][3], int m, int n)
{
    int output[3][3];
    output[m - 1][n - 1] = input[m - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        output[m - 1][i] = output[m - 1][i + 1] + input[m - 1][i];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
        }
    }
    return output[0][0];
}
int main()
{
    int m = 3, n = 3;
    int input[3][3] = {{5, 6, 7}, {54, 23, 89}, {12, 45, 67}};
    cout << min_cost_path_brute_force(input, m, n) << endl;

    int output[3][3] = {{-1, -1, 7}, {-1, -1, -1}, {-1, -1, -1}};
    cout << min_cost_path_memoization(input, m, n, output) << endl;
    cout << min_cost_path_DP(input, m, n) << endl;
}