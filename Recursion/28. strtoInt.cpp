/*
Covert a string number input to a integer using recursion
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int strToInt(char str[], int len, int place = 1, int num = 0)
{
    if (len == 0)
    {
        return num;
    }
    else
    {
        char c = str[len - 1];
        int a = c - 48;
        num = num + (a * place);
        strToInt(str, len - 1, place * 10, num);
    }
}

int main()
{
    char str[] = "1204";
    cout << strToInt(str, 4);
}