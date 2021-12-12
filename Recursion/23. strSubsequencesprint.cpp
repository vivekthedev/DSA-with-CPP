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