/*
Problem Statement: Check redundant brackets
Problem Level: MEDIUM
Problem Description:
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.

Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.

Note:
You are not required to print the expected result. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second

Sample Input 1:
a+(b)+c

Sample Output 1:
true

Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.

Sample Input 2:
(a+b)

Sample Output 2:
false


*/
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    T *data;
    int capacity;
    int nextIndex;

public:
    Stack()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex++] = element;
    }
    T pop()
    {
        if (isEmpty())
        {
            // cout << "Stack is empty\n";
            return 0;
        }
        else
            return data[--nextIndex];
    }
    T top()
    {
        if (isEmpty())
        {
            // cout << "Stack is empty\n";
            return 0;
        }
        else
            return data[nextIndex - 1];
    }
};

int main()
{
    Stack<char> s;
    string eq = "(a+b)";
    int i = 0, c = 0, flag = 0;
    while (i < eq.length())
    {
        if (eq[i] == ')')
        {
            c = 0;
            while (s.top() != '(')
            {
                s.pop();
                c++;
            }
            s.pop();
            c++;
            if (c >= 3 && s.size() == 0)
            {
                flag = 1;
                break;
            }
            else if (c < 3)
            {
                flag = 0;
                break;
            }
        }
        else
        {
            s.push(eq[i]);
        }
        i++;
    }
    if (flag)
    {
        cout << "not redundant";
    }
    else
    {
        cout << "redundant";
    }
}