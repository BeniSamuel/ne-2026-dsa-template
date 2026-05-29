#include <iostream>
using namespace std;

struct Queue
{
    int *arr; // let's now change the queue to arr
    int front;
    int rear;
    int capacity;
    int size;

    Queue(int cap)
    {
        capacity = cap;
        front = rear = -1;
        arr = new int[capacity];
        size = 0;
    }

    void enqueue(int val)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue is full" << endl;
            int *newArr = new int[capacity * 2];

            for (int i = front; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            rear = capacity - 1;
            capacity = capacity * 2;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        arr[rear] = val;
        size++;
    }

    void dequeue()
    {
        if (front == -1 || front > rear) // Fixed condition
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            cout << "The removed element in the queue is: " << arr[front] << endl;
            front++;
            size--;

            // Reset queue if it's empty after removal
            if (front > rear)
            {
                front = rear = -1;
                size = 0;
            }
        }
    }

    int getFrontElement()
    {
        if (front == -1 || front > rear)
        {
            return -1; // Return -1 to indicate an empty queue
        }
        else
        {
            return arr[front];
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << "The element at index: " << i << " = " << arr[i] << endl;
        }
    }

    int lengthQueue()
    {
        return size;
    }

    int getCount()
    {
        return size;
    }

    void isEmpty()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue is not empty" << endl;
        }
    }

    bool isFull()
    {
        return (size == capacity);
    }
};

int main()
{
    // Queue q(10);
    Queue *q = new Queue(5);

    cout << "Start adding elements: " << endl;
    q->enqueue(5);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);
    q->enqueue(70);
    q->display();

    q->dequeue();
    q->dequeue();
    q->display();

    q->isEmpty();
    cout << "Queue size: " << q->getCount() << endl;

    return 0;
}
