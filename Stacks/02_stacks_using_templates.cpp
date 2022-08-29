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
            cout << "Stack is empty\n";
            // return NULL;
        }
        else
            return data[--nextIndex];
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            // return NULL;
        }
        else
            return data[nextIndex - 1];
    }
};

int main()
{
    Stack<int> s1;
    Stack<char> s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push('V');
    s2.push('i');
    s2.push('v');
    s2.push('e');
    s2.push('k');
    cout << s1.pop() << endl;
    cout << s2.top();
}