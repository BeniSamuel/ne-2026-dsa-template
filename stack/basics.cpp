#include <iostream>
using namespace std;

// int numbers[5];
// int nextIndex = 0;

// void push ( int value ) {
//     numbers[nextIndex] = value;
//     nextIndex ++;
//     cout << "Added";
// }

// int peek () {
//     return numbers[nextIndex];
// }

// void pop () {
//     delete numbers[nextIndex];
// }

// bool isEmpty () {
//     if (nextIndex == 0 ) {
//         return true;
//     }
//     return false;
// }

// Teacher Implementation

struct Stack
{
    int *arr;
    int nextIndex;
    int capacity;

    Stack()
    {
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0;
    }

    Stack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }

    int returnSize()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        if (nextIndex == 0)
        {
            return true;
        }
        return false;
    }

    void push(int elem)
    {
        if (nextIndex == capacity)
        {
            cout << "Arr is full" << endl;
            return;
        }
        arr[nextIndex] = elem;
        nextIndex++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!!";
            return;
        }
        nextIndex--;
    }

    int top()
    {
        if (isEmpty())
        {
            return 0;
        }
        return arr[nextIndex - 1];
    }
};

int main()
{

    Stack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // This will not add an element cause it exceeds the capacity
    s.push(5);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    return 0;
}