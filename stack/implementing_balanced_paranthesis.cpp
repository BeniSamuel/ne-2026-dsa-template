#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char val;
    Node *next;
    Node(char val)
    {
        this->val = val;
        next = nullptr;
    }
};

struct stack
{

    Node *head;
    int sizeL;

    stack()
    {
        head = nullptr;
        sizeL = 0;
    }

    bool isEmpty()
    {
        return sizeL == 0;
    }

    int size()
    {
        return sizeL;
    }

    void push(char elem)
    {
        Node *newNode = new Node(elem);
        newNode->next = head;
        head = newNode;
        sizeL++;
    }

    char top()
    {
        if (isEmpty())
        {
            cout << "Stack Empty";
            return '\0'; // Return null character to indicate empty stack
        }
        return head->val;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        sizeL--;
    }
};

bool isBalanced(string brack)
{

    stack st;
    for (int i = 0; i < brack.length(); i++)
    {
        if (brack[i] == '(' || brack[i] == '{' || brack[i] == '[')
        {
            st.push(brack[i]);
        }
        else
        {
            if (!st.isEmpty() &&
                ((st.top() == '(' && brack[i] == ')') ||
                 (st.top() == '{' && brack[i] == '}') ||
                 (st.top() == '[' && brack[i] == ']')))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.isEmpty();
}

int main()
{

    string s = "{([])}";
    if (isBalanced(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}
