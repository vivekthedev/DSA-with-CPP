#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int totalSize;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        totalSize = s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {
        if (size == totalSize)
        {
            T *newData = new T[totalSize * 2];
            int j = 0;
            for (int i = firstIndex; i < totalSize; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = totalSize;
            totalSize *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % totalSize;
        if (firstIndex == -1)
        {
            firstIndex++;
        }
        size++;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % totalSize;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main()
{
    QueueUsingArray<int> q(5);
    q.enqueue(45);
    q.enqueue(435);
    q.enqueue(55);
    q.enqueue(15);
    q.enqueue(75);
    q.enqueue(7);
    cout << q.front() << endl;
}