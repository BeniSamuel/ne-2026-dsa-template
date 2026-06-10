#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Question:
    Given task dependencies, print one valid topological order.

Requirements:
    If edge u -> v exists, task u must be done before task v.

Strategy:
    Use Kahn's algorithm:
    count indegrees, push all zero-indegree vertices, then remove them.

Complexity:
    Time O(V + E), space O(V).
*/

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    queue<int> q;
    vector<int> order;

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    return order;
}

int main() {
    vector<vector<int>> adj(6);
    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    vector<int> order = topologicalSort(adj);
    cout << "Topological order: ";
    for (int task : order) cout << task << " ";
    cout << "\n";
    return 0;
}
