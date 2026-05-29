#include <iostream>
using namespace std;

struct Queue
{
    int front = -1;
    int rear = -1;
    int size = 100;
    int queue[100];

    void enqueue(int val)
    {
        if (rear == size - 1)
        {
            cout << "The Queue is full" << endl;
        }
        else
        {
            if (front == -1) // First element to be enqueued
            {
                front = 0;
            }
            rear++;
            queue[rear] = val;
            cout << "Added Successfully!!" << endl;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Element at front: " << queue[front] << endl;
            front++;
        }
    }

    int getFrontElement()
    {
        if (front == -1 || front > rear)
        {
            return -1;
        }
        else
        {
            return queue[front];
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "Element at index " << i << ": " << queue[i] << endl;
            }
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    int frontElement = q.getFrontElement();
    if (frontElement != -1)
    {
        cout << "Front element: " << frontElement << endl;
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
    return 0;
}
