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

int getLength(Node *head)
{
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node *lastNodeToFirst(Node *head, int n)
{
    int len = getLength(head);
    int c = (len - n) - 2;
    Node *temp = head;
    while (c != 0)
    {
        temp = temp->next;
        c--;
    }

    Node *curr = temp->next;
    temp->next = NULL;
    Node *temp2 = curr;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = head;
    return curr;
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

int main()
{
    Node *head = takeInput();
    head = lastNodeToFirst(head, 3);
    print(head);
}