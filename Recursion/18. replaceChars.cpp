#include <iostream>
using namespace std;
void replaceChar(char s[], char c1, char c2)
{
    if (s[0] == '\0')
    {
        return;
    }
    else if (s[0] == c1)
    {
        s[0] = c2;
    }
    replaceChar(s + 1, c1, c2);
}

int main()
{
    char str[] = "vivek";
    replaceChar(str, 'v', 'b');
    cout << str;
}