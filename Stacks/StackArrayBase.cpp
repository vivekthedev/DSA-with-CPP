#include <iostream>
#include <climits>
using namespace std;
class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    void push(int element)
    {
        if (capacity == nextIndex)
        {
            cout << "Stack is full \n";
            return;
        }
        data[nextIndex++] = element;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return data[--nextIndex];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
