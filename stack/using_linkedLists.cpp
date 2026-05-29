#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};

struct Stack
{
    Node *head;
    int size;

    Stack()
    {
        head = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }

    void push(int ele)
    {
        Node *newNode = new Node(ele);
        if (isEmpty())
        {
            head = newNode;
            size++;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!!";
        }

        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    Node *top()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        return head;
    }
};