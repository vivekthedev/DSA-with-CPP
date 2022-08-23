#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T element)
    {
        this->data = element;
        this->next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
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
        Node<T> *node = new Node<T>(element);
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            Node<T> *temp;
            temp = head;
            head = node;
            node->next = temp;
        }
    }
    T front()
    {
        if (head == NULL)
        {
            cout << "Queue is full\n";
            return 0;
        }
        return head->data;
    }
    T dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is full\n";
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head->next;
        delete head;
        head = temp;
        return ans;
    }
};

int main()
{
    Queue<int> q;
    cout << q.isEmpty() << endl;
    cout << q.getSize() << endl;
    for (int i = 0; i < 5; i++)
    {
        q.enqueue(i * 10);
    }
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
}