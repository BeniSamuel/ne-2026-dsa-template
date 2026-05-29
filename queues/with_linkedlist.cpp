#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int va)
    {
        val = va;
        next = nullptr;
    }
};

struct Queue
{
    Node *head;
    Node *tail;
    int size;

    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    // int count () {

    // }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int ele)
    {
        Node *newNode = new Node(ele);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        size--;
    }

    int front()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->val;
    }

    void display()
    {
        Node *temp = head;
        while (temp == nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
}

int
main()
{

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << q.front()

                return 0;
};
