#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }

    void inOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversal(node->left);
        cout << node->data << "->";
        inOrderTraversal(node->right);
    }

    void preOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->data << "->";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << "->";
    }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        this->root = nullptr;
    }

    Node *addNode(Node *subTree, int data, bool isRight)
    {
        Node *newNode = new Node(data);
        if (subTree == nullptr)
        {
            root = newNode;
            return root;
        }

        if (isRight == true)
        {
            subTree->right = newNode;
            return newNode;
        }

        else
        {
            subTree->left = newNode;
            return newNode;
        }
    }

    void display(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->data << " ";
        display(root->left);
        display(root->right);
    }
};

int main()
{
    BinaryTree bt;
    Node *root = bt.addNode(nullptr, 1, false);
    Node *left = bt.addNode(root, 2, false);
    Node *right = bt.addNode(root, 3, true);
    bt.addNode(left, 4, false);
    bt.addNode(left, 5, true);
    bt.addNode(right, 6, false);
    bt.addNode(right, 7, true);
    bt.display(root);

    return 0;
}
