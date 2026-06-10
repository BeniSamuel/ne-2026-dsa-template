#include <iostream>
#include <queue>
using namespace std;

/*
Purpose:
    Build a binary tree manually and print common traversals.

Example tree:
            1
          /   \
         2     3
        / \     \
       4   5     6

Traversal meanings:
    Inorder: Left, Root, Right
    Preorder: Root, Left, Right
    Postorder: Left, Right, Root
    Level order: Breadth-first by levels

Time complexity:
    Each traversal: O(n), because every node is visited once.

Space complexity:
    Recursive traversals: O(h), where h is tree height.
    Level order: O(w), where w is maximum width of the tree.
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

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Binary Tree:\n";
    cout << "        1\n";
    cout << "      /   \\\n";
    cout << "     2     3\n";
    cout << "    / \\     \\\n";
    cout << "   4   5     6\n\n";

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";

    cout << "Preorder: ";
    preorder(root);
    cout << "\n";

    cout << "Postorder: ";
    postorder(root);
    cout << "\n";

    cout << "Level order: ";
    levelOrder(root);
    cout << "\n";

    return 0;
}
