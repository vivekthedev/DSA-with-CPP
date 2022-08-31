#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int e)
    {
        this->data = e;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DQueue
{
    Node *head;
    Node *tail;
    int capacity;
    int size;

public:
    DQueue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    void insert_front(int e)
    {
        if (size == capacity)
        {
            cout << "Queue is full \n";
            return;
        }
        Node *temp = this->head;
        Node *node = new Node(e);
        node->next = temp;
        this->head = node;
        this->size += 1;
    }
    void insert_rear(int e)
    {
        if (size == capacity)
        {
            cout << "Queue is full \n";
            return;
        }
        Node *temp = this->tail;
        Node *node = new Node(e);
        node->prev = temp;
        this->tail = node;
        this->size += 1;
    }
    int delete_front()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        Node *temp = this->head;
        head = head->next;
        int ans = temp->data;
        delete temp;
        return ans;
    }
    int delete_rear()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        Node *temp = this->tail;
        tail = tail->prev;
        int ans = temp->data;
        delete temp;
        return ans;
    }
    int get_front()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->data;
    }
    int get_rear()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return tail->data;
    }
};