#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Question:
    Given a weighted graph, find shortest distances from source vertex 0.

Requirements:
    Use Dijkstra. All weights must be non-negative.

Strategy:
    Keep the smallest known distance for each vertex.
    Use a priority queue to always expand the closest vertex first.

Complexity:
    Time O((V + E) log V), space O(V + E).
*/

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int source) {
    const int INF = 1000000000;
    vector<int> dist(adj.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int main() {
    vector<vector<pair<int, int>>> adj(5);
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);

    vector<int> dist = dijkstra(adj, 0);
    for (int i = 0; i < (int)dist.size(); i++) {
        cout << "Distance from 0 to " << i << " = " << dist[i] << "\n";
    }
    return 0;
}
