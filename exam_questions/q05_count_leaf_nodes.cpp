#include <iostream>
using namespace std;

/*
Question:
    Count the number of leaf nodes in a binary tree.

Requirements:
    A leaf node has no left child and no right child.

Strategy:
    Recursively count leaves in the left and right subtrees.

Complexity:
    Time O(n), space O(h).
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Tree:\n";
    cout << "        1\n      /   \\\n     2     3\n    / \\     \\\n   4   5     6\n\n";
    cout << "Leaf nodes: " << countLeaves(root) << "\n";
    return 0;
}
