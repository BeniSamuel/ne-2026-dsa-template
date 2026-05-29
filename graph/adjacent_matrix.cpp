#include <iostream>
using namespace std;

class AdjacencyMatrix
{
private:
    int n;
    int **adj;

public:
    AdjacencyMatrix(int n)
    {

        /*Initializing an empty matrix
         */

        this->n = n;
        adj = new int *[n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }

        display();
    }

    void add_edge(int origin, int destin)
    {
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n";
            return;
        }

        adj[origin - 1][destin - 1] = 1;
    }

    void delete_edge(int origin, int destin)
    {
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = 0;
    }

    void display()
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
                cout << endl;
            }
        }
    }
};

int main()
{

    int nodes, edges, origin, destin;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    if (edges > (nodes * nodes))
    {
        cout << "Invalid number of edges!!";
        return 0;
    }

    AdjacencyMatrix am(nodes);
    for (int i = 0; i < edges; i++)
    {
        cout << "Edges number: " << i + 1 << endl;
        cout << "Enter edge (-1 -1 to exit)" << endl;
        cout << "Enter Origin and destination vertices: " << endl;

        cin >> origin >> destin;
        if (origin == -1 || destin == -1)
        {
            break;
        }
        am.add_edge(origin, destin);
    }
    am.display();

    am.delete_edge(1, 2);
    am.delete_edge(2, 2);
    cout << "After deleting two edges" << endl;
    am.display();

    return 0;
}