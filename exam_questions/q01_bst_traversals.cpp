#include <iostream>
using namespace std;

/*
Question:
    Build a BST from given values and display inorder, preorder, and postorder.

Requirements:
    Insert: 50, 30, 70, 20, 40, 60, 80
    Print all three DFS traversals.

Strategy:
    Insert smaller values to the left and larger values to the right.
    Then apply recursive traversal rules.

Complexity:
    Insert average O(log n), worst O(n). Traversals O(n). Space O(h).
*/

struct Node {


    
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    for (int value : {50, 30, 70, 20, 40, 60, 80}) root = insert(root, value);

    cout << "BST:\n";
    cout << "        50\n      /    \\\n    30      70\n   /  \\    /  \\\n 20   40  60   80\n\n";
    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n";
    return 0;
}
