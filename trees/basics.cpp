#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();

        cout << "Enter no of children of" << f->data << endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int childData;
            cout << "Enter: " << i << "The child of" << f->data << endl;
            cin >> childData;

            TreeNode<int> *child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << ": ";
    for (size_t i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ,";
    }
    cout << endl;

    for (size_t i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void printTreeLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    int counter = 0;

    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        counter++;
        q.pop();
        cout << f->data << ": ";
        for (size_t i = 0; i < f->children.size(); i++)
        {
            cout << f->children[i]->data << " ,";
        }
        cout << endl;
        for (size_t i = 0; i < f->children.size(); i++)
        {
            q.push(f->children[i]);
        }
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << "Print tree recursively" << endl;
    printTree(root);
    cout << "Printing Level wise" << endl;
    printTreeLevelWise(root);
    return 0;
}
