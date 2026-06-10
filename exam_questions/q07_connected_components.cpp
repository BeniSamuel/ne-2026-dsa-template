#include <iostream>
#include <vector>
using namespace std;

/*
Question:
    Count and print connected components in an undirected graph.

Requirements:
    Print every component separately.

Strategy:
    Run DFS from every unvisited vertex. Each DFS call discovers one component.

Complexity:
    Time O(V + E), space O(V).
*/

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<vector<int>>& adj, int u, vector<int>& visited) {
    visited[u] = 1;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) dfs(adj, v, visited);
    }
}

int main() {
    vector<vector<int>> adj(7);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);

    vector<int> visited(7, 0);
    int count = 0;

    for (int i = 0; i < 7; i++) {
        if (!visited[i]) {
            count++;
            cout << "Component " << count << ": ";
            dfs(adj, i, visited);
            cout << "\n";
        }
    }

    cout << "Total components: " << count << "\n";
    return 0;
}
