#include <iostream>
#include <limits>
using namespace std;

/*
Purpose:
    Common binary tree utility problems:
    height, count nodes, count leaves, mirror tree, and check BST validity.

Example tree before mirror:
            8
          /   \
         3     10
        / \      \
       1   6      14

After mirror:
            8
          /   \
        10     3
       /      / \
      14     6   1

Time complexity:
    Each utility visits each node at most once: O(n)

Space complexity:
    O(h) recursion stack.
*/

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

void mirror(Node* root) {
    if (root == nullptr) {
        return;
    }

    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

bool isBstInRange(Node* root, long long minValue, long long maxValue) {
    if (root == nullptr) {
        return true;
    }
    if (root->data <= minValue || root->data >= maxValue) {
        return false;
    }
    return isBstInRange(root->left, minValue, root->data) &&
           isBstInRange(root->right, root->data, maxValue);
}

bool isValidBst(Node* root) {
    return isBstInRange(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    cout << "Tree before mirror:\n";
    cout << "        8\n";
    cout << "      /   \\\n";
    cout << "     3     10\n";
    cout << "    / \\      \\\n";
    cout << "   1   6      14\n\n";

    cout << "Inorder before mirror: ";
    inorder(root);
    cout << "\n";
    cout << "Height: " << height(root) << "\n";
    cout << "Total nodes: " << countNodes(root) << "\n";
    cout << "Leaf nodes: " << countLeaves(root) << "\n";
    cout << "Valid BST: " << (isValidBst(root) ? "Yes" : "No") << "\n";

    mirror(root);

    cout << "\nTree after mirror:\n";
    cout << "        8\n";
    cout << "      /   \\\n";
    cout << "    10     3\n";
    cout << "   /      / \\\n";
    cout << "  14     6   1\n\n";

    cout << "Inorder after mirror: ";
    inorder(root);
    cout << "\n";
    cout << "Valid BST after mirror: " << (isValidBst(root) ? "Yes" : "No") << "\n";

    return 0;
}
