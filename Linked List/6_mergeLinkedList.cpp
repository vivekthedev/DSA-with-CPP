/*
Merge two sorted linked list
*/

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

Node *mergeList(Node *head, Node *head2)
{
    Node *headF = NULL;
    Node *tailF = NULL;
    if (head->data < head2->data)
    {
        headF = head;
        tailF = head;
        head = head->next;
    }
    else
    {
        headF = head2;
        tailF = head2;
        head2 = head2->next;
    }
    while (head != NULL && head2 != NULL)
    {
        if (head->data < head2->data)
        {
            tailF->next = head;
            tailF = tailF->next;
            head = head->next;
        }
        else
        {
            tailF->next = head2;
            tailF = tailF->next;
            head2 = head2->next;
        }
    }
    if (head == NULL)
    {
        while (head2 != NULL)
        {
            tailF->next = head2;
            tailF = tailF->next;
            head2 = head2->next;
        }
    }
    else
    {

        while (head != NULL)
        {
            tailF->next = head;
            tailF = tailF->next;
            head = head->next;
        }
    }
    tailF->next = NULL;
    return headF;
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
    Node *head = NULL;
    Node *head2 = NULL;
    head = takeInput();
    head2 = takeInput();

    Node *newHead = mergeList(head, head2);
    print(newHead);
}