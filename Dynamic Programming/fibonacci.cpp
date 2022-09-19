#include <iostream>
using namespace std;

int fibonacci(int num)
{
    if (num <= 1)
    {
        return num;
    }
    int a = fibonacci(num - 1);
    int b = fibonacci(num - 2);
    return a + b;
}

int fibonacci_dp_helper(int n, int *ans)
{
    if (n <= 1)
    {
        return n;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = fibonacci_dp_helper(n - 1, ans);
    int b = fibonacci_dp_helper(n - 2, ans);
    ans[n] = a + b;
    return ans[n];
}

int fibonacci_dp(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fibonacci_dp_helper(n, ans);
}
int main()
{
    cout << fibonacci_dp(6);
}