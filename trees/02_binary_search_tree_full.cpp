#include <iostream>
#include <limits>
using namespace std;

/*
Purpose:
    Complete Binary Search Tree template:
    insert, search, delete, find min, find max, and validate BST.

Example before deletion:
            50
          /    \
        30      70
       /  \    /  \
     20   40  60   80

After deleting 30:
            50
          /    \
        40      70
       /       /  \
     20       60   80

Time complexity:
    Average insert/search/delete: O(log n)
    Worst insert/search/delete: O(n), when the tree becomes skewed.
    Find min/max: O(h)
    Validate BST: O(n)

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

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
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

Node* findMinNode(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* findMaxNode(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* successor = findMinNode(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }

    return root;
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
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int value : values) {
        root = insert(root, value);
    }

    cout << "BST before deletion:\n";
    cout << "        50\n";
    cout << "      /    \\\n";
    cout << "    30      70\n";
    cout << "   /  \\    /  \\\n";
    cout << " 20   40  60   80\n\n";

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << "\n";

    cout << "Search 60: " << (search(root, 60) ? "Found" : "Not found") << "\n";
    cout << "Minimum: " << findMinNode(root)->data << "\n";
    cout << "Maximum: " << findMaxNode(root)->data << "\n";
    cout << "Valid BST: " << (isValidBst(root) ? "Yes" : "No") << "\n";

    root = deleteNode(root, 30);

    cout << "\nAfter deleting 30:\n";
    cout << "        50\n";
    cout << "      /    \\\n";
    cout << "    40      70\n";
    cout << "   /       /  \\\n";
    cout << " 20       60   80\n\n";

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << "\n";

    return 0;
}
