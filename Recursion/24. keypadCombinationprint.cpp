#include <iostream>
using namespace std;

string keymap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printCombinations(int num, string output = "")
{
    if (num == 0)
    {
        cout << output << "\n";
    }
    int lastDigit = num % 10;
    for (int i = 0; i < keymap[lastDigit].length(); i++)
    {
        printCombinations(num / 10, output + keymap[lastDigit][i]);
    }
}
int main()
{
    printCombinations(23);
}