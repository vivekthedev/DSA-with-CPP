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
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

// Insert at nth position
Node *insert(int data, Node *head, int j)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    int count = 0;
    if (j == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (count++ < j - 1 && temp != NULL)
    {

        temp = temp->next;
    }

    Node *a = temp->next;
    temp->next = newNode;
    newNode->next = a;
    return head;
}

Node *deleteElement(int i, Node *head)
{
    if (i == 0)
    {
        head = head->next;
        return head;
    }
    Node *temp = head;
    int count = 0;
    while (count++ < i - 2)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = del->next;
    delete del;
}
int main()
{
    // Statically
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    n1.next = &n2; // Two nodes are connected
    // Dynamically
    Node *n3 = new Node(10);
    Node *n4 = new Node(20);
    n3->next = n4;
    return 0;
}