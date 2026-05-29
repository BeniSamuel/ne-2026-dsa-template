#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;

    if (!s.empty())
    {
        cout << s.top() << endl;
    }
    else
    {
        cout << "Stack is empty!" << endl;
    }

    cout << "Size: " << s.size() << endl;

    // Adding elements
    s.push(10);
    s.push(20);
    s.push(40);
    s.push(50);
    s.push(60);

    // Printing the size of the stack
    cout << "Size now: " << s.size() << endl;

    s.pop();
    cout << "Empty Bool: " << s.empty() << endl;

    // Uncomment this loop to display all elements before emptying the stack
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
