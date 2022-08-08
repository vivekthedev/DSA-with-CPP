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

class LinkedList
{
public:
    Node *head;

    void create(int data)
    {
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "No item in the list\n";
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " => ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    LinkedList *MergeLinkedList(LinkedList *List)
    {
        LinkedList *new_LinkedList = new LinkedList();
        Node *h1 = this->head;
        Node *h2 = List->head;

        while (h1 != NULL && h2 != NULL)
        {
            if (h1->data < h2->data)
            {
                new_LinkedList->create(h1->data);
                h1 = h1->next;
            }
            else
            {

                new_LinkedList->create(h2->data);
                h2 = h2->next;
            }
        }
        if (h1 == NULL)
        {
            while (h2 != NULL)
            {
                new_LinkedList->create(h2->data);
                h2 = h2->next;
            }
        }
        else if (h2 == NULL)
        {
            while (h1 != NULL)
            {
                new_LinkedList->create(h1->data);
                h1 = h1->next;
            }
        }
        return new_LinkedList;
    }
    LinkedList()
    {
        this->head = NULL;
    }
};

int main()
{
    LinkedList l1, l2;
    int arr[5] = {1, 52, 75, 118, 135};
    int arr2[5] = {13, 42, 97, 432, 991};
    for (int i = 0; i < 5; i++)
    {
        l1.create(arr[i]);
    }
    l1.display();

    for (int i = 0; i < 5; i++)
    {
        l2.create(arr2[i]);
    }
    l2.display();

    cout << "\n\n\n";
    LinkedList *l3 = l1.MergeLinkedList(&l2);
    l3->display();
    return 0;
}
