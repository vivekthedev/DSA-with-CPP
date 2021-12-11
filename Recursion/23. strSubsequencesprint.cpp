#include <iostream>
using namespace std;
void strSubSeq(string input, string output = "")
{
    if (input.empty())
    {
        cout << output << " ";
        return;
    }
    strSubSeq(input.substr(1), output);
    strSubSeq(input.substr(1), output + input[0]);
}
int main()
{
    strSubSeq("1123");
}