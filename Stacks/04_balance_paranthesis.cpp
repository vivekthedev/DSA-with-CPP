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
            for (int i; i < capacity; i++)
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
            cout << "Stack is empty\n";
            return 0;
        }
        else
            return data[--nextIndex];
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return 0;
        }
        else
            return data[nextIndex - 1];
    }
};

int main()
{
    // string correct = "2+{675*(9+3)-78[7/89]+(4+3)}";
    string correct = "2+{675*(9+3-787/89]+(4+3)}";
    Stack<char> s1;
    int c = 0, flag = 0;
    while (c < correct.length())
    {
        if (correct[c] == '(' || correct[c] == '[' || correct[c] == '{')
        {
            s1.push(correct[c]);
        }
        else if (correct[c] == ')' || correct[c] == ']' || correct[c] == '}')
        {
            if (correct[c] == ')')
            {
                if (s1.top() == '(')
                    s1.pop();
            }
            else if (correct[c] == '}')
            {
                if (s1.top() == '{')
                    s1.pop();
            }
            else if (correct[c] == ']')
            {
                if (s1.top() == '[')
                    s1.pop();
            }

            flag = 1;
            break;
        }
        c++;
    }
    if (flag == 0 || s1.isEmpty() == true)
    {
        cout << flag << "  " << s1.top() << endl;
        cout << "Valid Expression";
    }
    else
    {
        cout << "Not Valid Expression";
    }
}