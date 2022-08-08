// Coding Problem
// Problem Statement: Reverse LL (Iterative)
// Problem Level: EASY
// Problem Description:
// Given a linked list, reverse it iteratively.
// You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.
// `Input format : Linked list elements (separated by space and terminated by -1)``

// Sample Input 1 :
// 1 2 3 4 5 -1

// Sample Output 1 :
// 5 4 3 2 1

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

Node *reverseLLIterative(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL)
    {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    Node *head = NULL;
    head = takeInput();
    print(head);
    cout << endl;
    head = reverseLLIterative(head);
    print(head);
    return 0;
}