#include <algorithm>
#include <iostream>
using namespace std;

/*
Question:
    Insert values into an AVL tree and search for given keys.

Requirements:
    Insert 30, 20, 10, 25, 40, 50.
    Show preorder after balancing and search for 25 and 99.

Strategy:
    Perform normal BST insertion, update heights, calculate balance,
    and apply rotations when balance is outside [-1, 1].

Complexity:
    Insert O(log n), search O(log n), space O(log n).
*/

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* node) {
    return node == nullptr ? 0 : node->height;
}

void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;
    x->right = y;
    y->left = temp;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;
    y->left = x;
    x->right = temp;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    else return root;

    updateHeight(root);
    int balance = height(root->left) - height(root->right);

    if (balance > 1 && value < root->left->data) return rightRotate(root);
    if (balance < -1 && value > root->right->data) return leftRotate(root);
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node* root, int value) {
    if (!root) return false;
    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;
    for (int value : {30, 20, 10, 25, 40, 50}) root = insert(root, value);

    cout << "AVL preorder: ";
    preorder(root);
    cout << "\n";
    cout << "Search 25: " << (search(root, 25) ? "Found" : "Not found") << "\n";
    cout << "Search 99: " << (search(root, 99) ? "Found" : "Not found") << "\n";
    return 0;
}
