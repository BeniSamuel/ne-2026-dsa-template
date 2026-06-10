#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Question:
    Find the minimum spanning tree cost using Prim's algorithm.

Requirements:
    Work on a connected, undirected, weighted graph.

Strategy:
    Start from vertex 0. Always choose the cheapest edge that connects
    a new vertex to the growing MST.

Complexity:
    Time O(E log V), space O(V + E).
*/

void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int prim(vector<vector<pair<int, int>>>& adj) {
    vector<int> inMst(adj.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int total = 0;

    pq.push({0, 0});
    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMst[u]) continue;
        inMst[u] = 1;
        total += weight;

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int cost = edge.second;
            if (!inMst[v]) pq.push({cost, v});
        }
    }

    return total;
}

int main() {
    vector<vector<pair<int, int>>> adj(5);
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);

    cout << "Prim MST total cost: " << prim(adj) << "\n";
    return 0;
}
