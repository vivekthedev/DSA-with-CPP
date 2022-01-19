#include <iostream>
using namespace std;

/*
The Data Structure of Dynamic Array provides a array with capacity that can be modifiable.
The Dynamic Array will get double in size whenever the capacity is full.

*/
class Dynamic_Array
{
    int *data;
    int nextIndex;
    int capacity;

public:
    Dynamic_Array()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int get(int i)
    {
        if (i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Dynamic_Array D;
    D.add(2);
    D.add(5);
    D.add(6);
    D.add(1);
    D.add(9);

    cout << D.get(4) << endl
         << D.get(2);
}