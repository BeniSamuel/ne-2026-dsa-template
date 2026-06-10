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
        newNode->next = head;
        head = newNode;
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!!" << endl;
            return;
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

    void display()
    {
        Node *current = head;
        cout << "Stack top -> bottom: ";
        while (current != nullptr)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    if (s.top() != nullptr)
    {
        cout << "Top element: " << s.top()->val << endl;
    }

    s.pop();
    s.display();
    cout << "Size: " << s.getSize() << endl;

    return 0;
}
