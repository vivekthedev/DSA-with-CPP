#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int findElement(int a, Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == a)
        {
            return count;
        }
        temp = temp->next;
        count++;
    }
}

int main()
{
    Node a(1);
    Node *head = &a;
    Node b(2);
    a.next = &b;
    Node c(3);
    b.next = &c;
    Node d(4);
    c.next = &d;

    cout << findElement(3, head);

    return 0;
}