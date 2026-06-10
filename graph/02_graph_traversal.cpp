#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/*
Purpose:
    BFS visits a graph level by level.
    DFS goes as deep as possible before backtracking.

Sample graph:
        0
       / \
      1   2
     / \   \
    3   4   5

Time complexity:
    BFS: O(V + E)
    DFS recursive: O(V + E)
    DFS iterative: O(V + E)

Space complexity:
    O(V) for visited array and queue/stack/recursion depth.
*/

void addUndirectedEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(const vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS order from " << start << ": ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbour : adj[current]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    cout << "\n";
}

void dfsRecursiveHelper(const vector<vector<int>>& adj, int current, vector<bool>& visited) {
    visited[current] = true;
    cout << current << " ";

    for (int neighbour : adj[current]) {
        if (!visited[neighbour]) {
            dfsRecursiveHelper(adj, neighbour, visited);
        }
    }
}

void dfsRecursive(const vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    cout << "DFS recursive order from " << start << ": ";
    dfsRecursiveHelper(adj, start, visited);
    cout << "\n";
}

void dfsIterative(const vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    st.push(start);

    cout << "DFS iterative order from " << start << ": ";
    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (visited[current]) {
            continue;
        }

        visited[current] = true;
        cout << current << " ";

        for (int i = (int)adj[current].size() - 1; i >= 0; i--) {
            int neighbour = adj[current][i];
            if (!visited[neighbour]) {
                st.push(neighbour);
            }
        }
    }
    cout << "\n";
}

int main() {
    vector<vector<int>> adj(6);

    addUndirectedEdge(adj, 0, 1);
    addUndirectedEdge(adj, 0, 2);
    addUndirectedEdge(adj, 1, 3);
    addUndirectedEdge(adj, 1, 4);
    addUndirectedEdge(adj, 2, 5);

    cout << "Sample graph edges: 0-1, 0-2, 1-3, 1-4, 2-5\n";
    bfs(adj, 0);
    dfsRecursive(adj, 0);
    dfsIterative(adj, 0);

    return 0;
}
