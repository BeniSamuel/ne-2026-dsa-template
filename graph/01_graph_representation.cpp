#include <iostream>
#include <vector>
using namespace std;

/*
Purpose:
    Show the two most common ways to store a graph:
    1. Adjacency Matrix: matrix[u][v] = 1 if edge u-v exists.
    2. Adjacency List: adj[u] stores all neighbours of u.

Sample graph:
        0
       / \
      1---2
      |
      3

Time complexity:
    Add edge in matrix: O(1)
    Check edge in matrix: O(1)
    Print matrix: O(V^2)
    Add edge in list: O(1)
    Check edge in list: O(degree of vertex)
    Print list: O(V + E)

Space complexity:
    Matrix: O(V^2)
    List: O(V + E)
*/

class GraphMatrix {
private:
    int vertices;
    vector<vector<int>> matrix;

public:
    GraphMatrix(int v) {
        vertices = v;
        matrix.assign(vertices, vector<int>(vertices, 0));
    }

    void addUndirectedEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    bool hasEdge(int u, int v) const {
        return matrix[u][v] == 1;
    }

    void print() const {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

class GraphList {
private:
    int vertices;
    vector<vector<int>> adj;

public:
    GraphList(int v) {
        vertices = v;
        adj.assign(vertices, vector<int>());
    }

    void addUndirectedEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool hasEdge(int u, int v) const {
        for (int neighbour : adj[u]) {
            if (neighbour == v) {
                return true;
            }
        }
        return false;
    }

    void print() const {
        cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int neighbour : adj[i]) {
                cout << neighbour << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int vertices = 4;

    GraphMatrix matrixGraph(vertices);
    GraphList listGraph(vertices);

    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};

    for (pair<int, int> edge : edges) {
        matrixGraph.addUndirectedEdge(edge.first, edge.second);
        listGraph.addUndirectedEdge(edge.first, edge.second);
    }

    cout << "Sample graph edges: 0-1, 0-2, 1-2, 1-3\n\n";
    matrixGraph.print();
    cout << "\n";
    listGraph.print();

    cout << "\nCheck edge 0-2 in matrix: "
         << (matrixGraph.hasEdge(0, 2) ? "Yes" : "No") << "\n";
    cout << "Check edge 2-3 in list: "
         << (listGraph.hasEdge(2, 3) ? "Yes" : "No") << "\n";

    return 0;
}
