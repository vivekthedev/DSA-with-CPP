#include <iostream>
using namespace std;
int strSubsequences(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string subStr = input.substr(1);
    int smallOutputSize = strSubsequences(subStr, output);
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return 2 * smallOutputSize;
}

int main()
{
    string s = "1123";
    string *out = new string[1000];
    int c = strSubsequences(s, out);
    for (int i = 0; i < c; i++)
    {
        cout << out[i] << endl;
    }
}