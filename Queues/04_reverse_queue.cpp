
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
            cout << "Queue is full\n";
            return;
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

template <typename T>
void reverse_queue(QueueUsingArray<T> q)
{
    int s = q.getSize() - 1;
    while (s--)
    {
        T temp = q.dequeue();
        q.enqueue(temp);
    }
}

int main()
{
    QueueUsingArray<int> q(5);
    q.enqueue(45);
    q.enqueue(435);
    q.enqueue(55);
    q.enqueue(15);
    cout << q.front() << endl;
    reverse_queue(q);
    cout << q.front() << endl;
}