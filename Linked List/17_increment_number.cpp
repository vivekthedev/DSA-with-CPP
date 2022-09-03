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

int reverseNum(int num)
{
    int rev = 0;
    while (num > 0)
    {
        rev = (rev * 10) + (num % 10);
        num /= 10;
    }
    return rev;
}

Node *makeNumber(int num)
{
    Node *head = NULL;
    Node *tail = NULL;
    num = reverseNum(num);
    while (num > 0)
    {
        Node *newNode = new Node(num % 10);
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
        num /= 10;
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

Node *incrementNumber(Node *head)
{
    int num = 0;
    while (head != NULL)
    {
        num = (num * 10) + head->data;
        head = head->next;
    }
    head = makeNumber(num + 1);
    return head;
}

int main()
{
    Node *head = makeNumber(874656789);
    head = incrementNumber(head);
    print(head);
}