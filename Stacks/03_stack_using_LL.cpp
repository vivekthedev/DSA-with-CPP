#include <iostream>
#include <climits>

using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        Node<T> *temp = head;
        head = newNode;
        newNode->next = temp;
        this->size = size + 1;
    }
    T pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        Node<T> *temp = head;
        head = head->next;
        T data = temp->data;
        delete temp;
        this->size = size - 1;
        return data;
    }
    T top()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return head->data;
    }
};

int main()
{
    Stack<int> s1;
    Stack<char> s2;
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout << s1.pop() << endl;
    cout << s1.top() << endl;
    cout << s1.getSize() << endl;

    s2.push('V');
    s2.push('I');
    s2.push('V');
    cout << s2.pop() << endl;
    cout << s2.top() << endl;
    cout << s2.getSize() << endl;
}