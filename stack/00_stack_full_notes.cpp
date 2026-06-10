#include <iostream>
#include <string>
using namespace std;

/*
STACK FULL NOTES - C++17

Analogy:
    A stack is like plates in a cafeteria. The last plate placed on top
    is the first plate removed. This is LIFO: Last In, First Out.

Exam scenarios:
    - Undo operation in an editor.
    - Browser back button.
    - Balanced parentheses checking.
    - Function call recursion.

Operations:
    push, pop, top/peek, isEmpty, isFull, size, display.

Complexity:
    Array stack operations: O(1)
    Linked stack operations: O(1)
    Space: O(n)
*/

class ArrayStack {
private:
    int* data;
    int capacity;
    int topIndex;

public:
    ArrayStack(int size) {
        capacity = size;
        data = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] data;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    int size() const {
        return topIndex + 1;
    }

    // Scenario: Place a plate on top.
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow: cannot push " << value << "\n";
            return;
        }

        topIndex++;
        data[topIndex] = value;
    }

    // Scenario: Remove the top plate.
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow: cannot pop\n";
            return -1;
        }

        int removed = data[topIndex];
        topIndex--;
        return removed;
    }

    int top() const {
        if (isEmpty()) {
            return -1;
        }
        return data[topIndex];
    }

    void display() const {
        cout << "Stack top -> bottom: ";
        for (int i = topIndex; i >= 0; i--) {
            cout << data[i] << " ";
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

class LinkedStack {
private:
    Node* head;

public:
    LinkedStack() {
        head = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    // Time: O(1)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Time: O(1)
    int pop() {
        if (isEmpty()) {
            return -1;
        }

        Node* temp = head;
        int removed = temp->data;
        head = head->next;
        delete temp;
        return removed;
    }

    int top() const {
        if (isEmpty()) {
            return -1;
        }
        return head->data;
    }
};

bool matchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Application: compiler checks whether brackets are correctly closed.
// Time: O(n), Space: O(n)
bool isBalanced(const string& text) {
    char stackArray[100];
    int top = -1;

    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stackArray[++top] = ch;
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1 || !matchingPair(stackArray[top], ch)) {
                return false;
            }
            top--;
        }
    }

    return top == -1;
}

// Application: reverse a word using LIFO behavior.
string reverseString(const string& text) {
    string result = "";
    char stackArray[100];
    int top = -1;

    for (char ch : text) {
        stackArray[++top] = ch;
    }

    while (top != -1) {
        result += stackArray[top--];
    }

    return result;
}

int main() {
    cout << "ARRAY STACK DEMO\n";
    ArrayStack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    cout << "Top: " << stack.top() << "\n";
    cout << "Popped: " << stack.pop() << "\n";
    stack.display();

    cout << "\nLINKED STACK DEMO\n";
    LinkedStack linked;
    linked.push(100);
    linked.push(200);
    cout << "Linked stack top: " << linked.top() << "\n";
    cout << "Linked stack pop: " << linked.pop() << "\n";

    cout << "\nSTACK APPLICATIONS\n";
    string expression = "{(a+b)*[c-d]}";
    cout << expression << " balanced: " << (isBalanced(expression) ? "Yes" : "No") << "\n";
    cout << "Reverse CODE: " << reverseString("CODE") << "\n";

    return 0;
}
