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

int midElement(Node *head)
{
    if (head != NULL)
    {
        Node *slow = head, *fast = head->next->next;
        while (fast != NULL)
        {
            slow = slow->next;
            if (fast->next != NULL)
            {
                fast = fast->next->next;
            }
            else
            {
                fast = fast->next;
            }
        }
        return slow->data;
    }
    return -1;
}

int main()
{
    Node *head = NULL;
    head = takeInput();
    cout << midElement(head);
}