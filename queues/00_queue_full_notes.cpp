#include <iostream>
using namespace std;

/*
QUEUE FULL NOTES - C++17

Analogy:
    A queue is like a line at a bank. The first person to enter the line
    is served first. This is FIFO: First In, First Out.

Exam scenarios:
    - Printer job scheduling.
    - BFS graph traversal.
    - Customer service lines.
    - CPU task scheduling.

Operations:
    enqueue: insert at rear
    dequeue: remove from front
    getFront: read front item
    getRear: read rear item
    isEmpty, isFull, size, display

Complexity:
    With circular array: all main operations are O(1).
    Space: O(capacity).
*/

class CircularQueue {
private:
    int* data;
    int capacity;
    int frontIndex;
    int rearIndex;
    int itemCount;

public:
    CircularQueue(int size) {
        capacity = size;
        data = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        itemCount = 0;
    }

    ~CircularQueue() {
        delete[] data;
    }

    bool isEmpty() const {
        return itemCount == 0;
    }

    bool isFull() const {
        return itemCount == capacity;
    }

    int size() const {
        return itemCount;
    }

    // Scenario: A new customer joins the back of the line.
    // Modulo makes the array circular, so rear wraps to index 0.
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow: cannot enqueue " << value << "\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = value;
        itemCount++;
    }

    // Scenario: The first customer is served and leaves.
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow: cannot dequeue\n";
            return -1;
        }

        int removed = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        itemCount--;
        return removed;
    }

    int getFront() const {
        if (isEmpty()) {
            return -1;
        }
        return data[frontIndex];
    }

    int getRear() const {
        if (isEmpty()) {
            return -1;
        }
        return data[rearIndex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue front -> rear: ";
        for (int i = 0; i < itemCount; i++) {
            int index = (frontIndex + i) % capacity;
            cout << data[index] << " ";
        }
        cout << "\n";
    }
};

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedQueue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    LinkedQueue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }

    // Dynamic queue: no fixed capacity unless memory is exhausted.
    // Time: O(1)
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    // Time: O(1)
    int dequeue() {
        if (isEmpty()) {
            cout << "Linked queue is empty\n";
            return -1;
        }

        Node* temp = frontNode;
        int removed = temp->data;
        frontNode = frontNode->next;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
        return removed;
    }

    void display() const {
        Node* current = frontNode;
        cout << "Linked queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

class SimplePriorityQueue {
private:
    int values[20];
    int priorities[20];
    int count;

public:
    SimplePriorityQueue() {
        count = 0;
    }

    // Lower priority number means more urgent.
    // Scenario: hospital emergency queue, priority 1 before priority 3.
    // Time: O(1) insert for this simple unsorted version.
    void enqueue(int value, int priority) {
        if (count == 20) {
            cout << "Priority queue is full\n";
            return;
        }

        values[count] = value;
        priorities[count] = priority;
        count++;
    }

    // Time: O(n) because we scan for the highest priority item.
    int dequeue() {
        if (count == 0) {
            cout << "Priority queue is empty\n";
            return -1;
        }

        int bestIndex = 0;
        for (int i = 1; i < count; i++) {
            if (priorities[i] < priorities[bestIndex]) {
                bestIndex = i;
            }
        }

        int removed = values[bestIndex];
        for (int i = bestIndex; i < count - 1; i++) {
            values[i] = values[i + 1];
            priorities[i] = priorities[i + 1];
        }
        count--;
        return removed;
    }
};

int main() {
    cout << "CIRCULAR QUEUE DEMO\n";
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front: " << q.getFront() << ", Rear: " << q.getRear() << "\n";
    cout << "Dequeued: " << q.dequeue() << "\n";
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    cout << "\nLINKED QUEUE DEMO\n";
    LinkedQueue linked;
    linked.enqueue(100);
    linked.enqueue(200);
    linked.enqueue(300);
    linked.display();
    cout << "Dequeued: " << linked.dequeue() << "\n";
    linked.display();

    cout << "\nPRIORITY QUEUE DEMO\n";
    SimplePriorityQueue emergency;
    emergency.enqueue(101, 3);
    emergency.enqueue(102, 1);
    emergency.enqueue(103, 2);
    cout << "First served patient id: " << emergency.dequeue() << "\n";

    return 0;
}
