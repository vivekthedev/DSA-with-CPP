#include <iostream>
#include "StackArrayBase.cpp"
using namespace std;

void adjust_brackets(string exp)
{
    StackUsingArray s(exp.length());
    int i = 0;
    if (exp.length() % 2 == 1)
    {
        cout << -1;
    }
    else
    {
        while (exp[i])
        {
            if (exp[i] == '}')
            {
                s.pop();
            }
            else
            {
                s.push(i);
            }
            i++;
        }
        while (s.size())
        {
            cout << s.pop() + 1 << " ";
            s.pop();
        }
    }
}

int main()
{
    string exp = "{{{{";
    adjust_brackets(exp);
}