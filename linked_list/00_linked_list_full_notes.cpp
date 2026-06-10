#include <iostream>
using namespace std;

/*
LINKED LIST FULL NOTES - C++17

Analogy:
    A linked list is like a treasure hunt. Each card stores a value and
    the address of the next card. To reach the 5th card, you must follow
    the chain from the first card.

Best exam scenarios:
    - When frequent insertion/deletion is needed near known positions.
    - When the number of items grows dynamically.
    - When learning pointers, node creation, and memory links.

Main operations covered:
    Singly linked list:
        insertFront, insertBack, insertAtPosition
        deleteFront, deleteBack, deleteValue
        search, length, reverse, findMiddle
    Doubly linked list:
        insertBack, deleteValue, displayForward, displayBackward
    Circular linked list:
        insertBack, display

Important complexity:
    Search: O(n)
    Insert/delete at head: O(1)
    Insert/delete at tail with no tail pointer: O(n)
    Reverse: O(n)
    Space: O(n)
*/

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Scenario: A new student joins the front of a registration line.
    // Time: O(1), Space: O(1)
    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Scenario: A student joins the end of a queue.
    // Time: O(n) because we walk to the last node.
    void insertBack(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Position is 1-based. position = 1 means insert at head.
    // Scenario: Insert a mark at a specific rank in a result list.
    // Time: O(n), Space: O(1)
    void insertAtPosition(int value, int position) {
        if (position <= 1 || head == nullptr) {
            insertFront(value);
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }

        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
    }

    // Scenario: First person leaves the line.
    // Time: O(1), Space: O(1)
    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete at front.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Scenario: Last person leaves the line.
    // Time: O(n), Space: O(1)
    void deleteBack() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete at back.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    // Deletes first occurrence of value.
    // Scenario: Remove a student id from a club list.
    // Time: O(n), Space: O(1)
    void deleteValue(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            deleteFront();
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << value << " was not found.\n";
            return;
        }

        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Scenario: Check whether a roll number exists.
    // Time: O(n), Space: O(1)
    bool search(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Time: O(n), Space: O(1)
    int length() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Analogy: Turn all arrows to point backward.
    // Time: O(n), Space: O(1)
    void reverse() {
        Node* previous = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        head = previous;
    }

    // Uses slow and fast pointers.
    // Analogy: One student walks one step, another walks two steps.
    // When fast reaches the end, slow is in the middle.
    // Time: O(n), Space: O(1)
    int findMiddle() const {
        if (head == nullptr) {
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};

struct DoublyNode {
    int data;
    DoublyNode* previous;
    DoublyNode* next;

    DoublyNode(int value) {
        data = value;
        previous = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Analogy: A train coach is connected to the coach before and after it.
    // Time: O(1) because a tail pointer is maintained.
    void insertBack(int value) {
        DoublyNode* newNode = new DoublyNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }

    // Time: O(n), Space: O(1)
    void deleteValue(int value) {
        DoublyNode* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        if (current->previous != nullptr) {
            current->previous->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->previous = current->previous;
        } else {
            tail = current->previous;
        }

        delete current;
    }

    void displayForward() const {
        DoublyNode* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() const {
        DoublyNode* current = tail;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->previous;
        }
        cout << "NULL\n";
    }
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    // Analogy: Students stand in a circle; the last points back to the first.
    // Scenario: Round-robin scheduling where turns repeat.
    // Time: O(1) because tail is maintained.
    void insertBack(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void display() const {
        if (tail == nullptr) {
            cout << "Empty circular list\n";
            return;
        }

        Node* current = tail->next;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != tail->next);

        cout << "(back to " << tail->next->data << ")\n";
    }
};

int main() {
    cout << "SINGLY LINKED LIST DEMO\n";
    SinglyLinkedList list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);
    list.insertFront(5);
    list.insertAtPosition(15, 3);
    cout << "After insertions: ";
    list.display();
    cout << "Length: " << list.length() << "\n";
    cout << "Search 20: " << (list.search(20) ? "Found" : "Not found") << "\n";
    cout << "Middle value: " << list.findMiddle() << "\n";

    list.deleteValue(20);
    cout << "After deleting 20: ";
    list.display();

    list.reverse();
    cout << "After reverse: ";
    list.display();

    cout << "\nDOUBLY LINKED LIST DEMO\n";
    DoublyLinkedList doubleList;
    doubleList.insertBack(1);
    doubleList.insertBack(2);
    doubleList.insertBack(3);
    cout << "Forward: ";
    doubleList.displayForward();
    cout << "Backward: ";
    doubleList.displayBackward();
    doubleList.deleteValue(2);
    cout << "After deleting 2: ";
    doubleList.displayForward();

    cout << "\nCIRCULAR LINKED LIST DEMO\n";
    CircularLinkedList circle;
    circle.insertBack(100);
    circle.insertBack(200);
    circle.insertBack(300);
    circle.display();

    return 0;
}
