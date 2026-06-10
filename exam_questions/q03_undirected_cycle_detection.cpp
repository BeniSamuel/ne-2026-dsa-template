#include <iostream>
#include <vector>
using namespace std;

/*
Question:
    Detect whether an undirected graph contains a cycle.

Requirements:
    Print Yes if a cycle exists, otherwise No.

Strategy:
    DFS with parent tracking. If a visited neighbour is not the parent,
    a cycle exists.

Complexity:
    Time O(V + E), space O(V).
*/

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(vector<vector<int>>& adj, int u, int parent, vector<int>& visited) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(adj, v, u, visited)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0);
    for (int i = 0; i < (int)adj.size(); i++) {
        if (!visited[i] && dfs(adj, i, -1, visited)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> adj(4);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    cout << "Cycle exists: " << (hasCycle(adj) ? "Yes" : "No") << "\n";
    return 0;
}
