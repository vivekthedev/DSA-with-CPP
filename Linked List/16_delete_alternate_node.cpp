#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int e)
    {
        this->data = e;
        this->next = NULL;
    }
};

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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void delete_alternate_elements(Node *head)
{
    Node *headC = head;
    while (headC != NULL && headC->next != NULL)
    {
        Node *temp = headC->next;
        headC->next = temp->next;
        headC = headC->next;
        delete temp;
    }
}
int main()
{
    Node *head = takeInput();
    delete_alternate_elements(head);
    print(head);
}