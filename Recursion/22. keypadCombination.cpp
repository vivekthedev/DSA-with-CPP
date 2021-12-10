/*
Problem Statement: Print Keypad - String
Problem Level: HARD
Problem Description:
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
using namespace std;

string keymap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypadCombinations(int num, string output[], int size = 0)
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    else
    {
        int lastDigit = num % 10;
        int remainingNum = num / 10;
        int charlen = keymap[lastDigit].length();
        string keyval = keymap[lastDigit];
        int size = keypadCombinations(remainingNum, output, size);
        for (int i = 1; i < charlen; i++)
        {
            int add = size * i;
            for (int j = 0; j < size; j++)
            {
                output[j + add] = output[j];
            }
        }
        for (int i = 0; i < charlen; i++)
        {
            int add = size * i;
            for (int j = 0; j < size; j++)
            {
                output[j + add] = output[j + add] + keyval[i];
            }
        }
        return size * charlen;
    }
}
int main()
{
    int num = 23;
    string output[1000];
    int size = keypadCombinations(num, output);

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}