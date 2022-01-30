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

void eliminateDuplicates(Node *head)
{
    if (head != NULL && head->next != NULL)
    {

        Node *t1 = head;
        Node *t2 = head->next;
        while (t2 != NULL)
        {
            if (t1->data == t2->data)
            {
                Node *temp = t2;
                t2 = t2->next;
                delete temp;
                t1->next = t2;
            }
            else
            {
                t1 = t1->next;
                t2 = t2->next;
            }
        }
    }
}

void main()
{
    Node *head = NULL;
    head = takeInput();
    eliminateDuplicates(head);
    print(head);
}