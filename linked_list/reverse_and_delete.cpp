#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    // Constructor initializes next to nullptr
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *deleteAtHead(Node *head)
{
    if (head == nullptr)
        return nullptr; // Handle empty list

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteAtEnd(Node *head)
{
    if (head == nullptr)
        return nullptr; // Handle empty list

    if (head->next == nullptr)
    {
        // If there's only one node, delete it and return nullptr
        delete head;
        return nullptr;
    }

    Node *secondLast = head;

    while (secondLast->next->next != nullptr)
    {
        secondLast = secondLast->next;
    }

    delete secondLast->next;
    secondLast->next = nullptr;
    return head;
}

Node *displayReverse(Node *head)
{

    Node *curr = head;
    Node *prev = nullptr;
    Node *nextNode = nullptr;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

void display(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    // recursive case
    // take a head pointer
    Node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main()
{
    Node *head = new Node(17);
    Node *h1 = new Node(10);
    Node *h2 = new Node(27);
    Node *h3 = new Node(37);
    Node *h4 = new Node(47);

    head->next = h1;
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;

    cout << "Printing reverse:" << endl;
    Node *reverseNode = displayReverse(head);
    display(reverseNode);

    Node *c = merge(head, h3);
    display(c);

    cout << "Original list: ";
    display(head);

    cout << "After deleting at head: ";
    head = deleteAtHead(head);
    display(head);

    cout << "After deleting at end: ";
    head = deleteAtEnd(head);
    display(head);

    return 0;
}
