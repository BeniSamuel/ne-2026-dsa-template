#include <algorithm>
#include <iostream>
using namespace std;

/*
Purpose:
    AVL Tree is a self-balancing BST.
    For every node, height(left) - height(right) must be -1, 0, or 1.

Rotation cases:
    Left Left: right rotation
    Right Right: left rotation
    Left Right: left rotation on left child, then right rotation
    Right Left: right rotation on right child, then left rotation

Example insertions: 30, 20, 10
Before balancing:
        30
       /
      20
     /
    10

After right rotation:
        20
       /  \
      10   30

Time complexity:
    Insert: O(log n)
    Search: O(log n)

Space complexity:
    O(h) recursion stack, where h = O(log n).
*/

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int balanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
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
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        return root;
    }

    updateHeight(root);
    int balance = balanceFactor(root);

    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }

    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }

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
    if (root == nullptr) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;
    int values[] = {30, 20, 10, 25, 40, 50};

    cout << "Insert order: 30, 20, 10, 25, 40, 50\n";
    cout << "First three insertions trigger a right rotation:\n";
    cout << "Before: 30 <- 20 <- 10\n";
    cout << "After:\n";
    cout << "      20\n";
    cout << "     /  \\\n";
    cout << "    10   30\n\n";

    for (int value : values) {
        root = insert(root, value);
    }

    cout << "AVL preorder after all insertions: ";
    preorder(root);
    cout << "\n";
    cout << "Search 25: " << (search(root, 25) ? "Found" : "Not found") << "\n";
    cout << "Search 99: " << (search(root, 99) ? "Found" : "Not found") << "\n";

    return 0;
}
