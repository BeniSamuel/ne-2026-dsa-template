#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

/*
Purpose:
    A complete runnable file for common national-exam graph algorithms:
    connected components, cycle detection, topological sort, Dijkstra,
    Prim, and Kruskal.

Complexities:
    Connected components: O(V + E) time, O(V) space
    Undirected cycle detection: O(V + E) time, O(V) space
    Directed cycle detection: O(V + E) time, O(V) space
    Topological sort: O(V + E) time, O(V) space
    Dijkstra with priority queue: O((V + E) log V) time, O(V + E) space
    Prim with priority queue: O(E log V) time, O(V + E) space
    Kruskal: O(E log E) time, O(V) extra space
*/

struct WeightedEdge {
    int u;
    int v;
    int weight;
};

void addUndirectedEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addDirectedEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

void dfsComponent(const vector<vector<int>>& adj, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfsComponent(adj, neighbour, visited);
        }
    }
}

void printConnectedComponents(const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    int componentNumber = 0;

    cout << "\nConnected Components:\n";
    for (int i = 0; i < (int)adj.size(); i++) {
        if (!visited[i]) {
            componentNumber++;
            cout << "Component " << componentNumber << ": ";
            dfsComponent(adj, i, visited);
            cout << "\n";
        }
    }
}

bool hasUndirectedCycleDfs(const vector<vector<int>>& adj, int node, int parent, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (hasUndirectedCycleDfs(adj, neighbour, node, visited)) {
                return true;
            }
        } else if (neighbour != parent) {
            return true;
        }
    }
    return false;
}

bool hasUndirectedCycle(const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);

    for (int i = 0; i < (int)adj.size(); i++) {
        if (!visited[i] && hasUndirectedCycleDfs(adj, i, -1, visited)) {
            return true;
        }
    }
    return false;
}

bool hasDirectedCycleDfs(const vector<vector<int>>& adj, int node, vector<int>& state) {
    state[node] = 1; // 1 means currently in recursion stack.

    for (int neighbour : adj[node]) {
        if (state[neighbour] == 1) {
            return true;
        }
        if (state[neighbour] == 0 && hasDirectedCycleDfs(adj, neighbour, state)) {
            return true;
        }
    }

    state[node] = 2; // 2 means completely processed.
    return false;
}

bool hasDirectedCycle(const vector<vector<int>>& adj) {
    vector<int> state(adj.size(), 0);

    for (int i = 0; i < (int)adj.size(); i++) {
        if (state[i] == 0 && hasDirectedCycleDfs(adj, i, state)) {
            return true;
        }
    }
    return false;
}

vector<int> topologicalSort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    vector<int> order;
    queue<int> q;

    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return order;
}

vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj, int source) {
    const int INF = numeric_limits<int>::max();
    vector<int> distance(adj.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDistance != distance[u]) {
            continue;
        }

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int primMst(const vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<bool> inMst(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int totalWeight = 0;

    pq.push({0, 0}); // {weight, vertex}

    cout << "\nPrim MST selected edges by endpoint:\n";
    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMst[u]) {
            continue;
        }

        inMst[u] = true;
        totalWeight += weight;
        cout << "Take vertex " << u << " with connecting weight " << weight << "\n";

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int edgeWeight = edge.second;
            if (!inMst[v]) {
                pq.push({edgeWeight, v});
            }
        }
    }

    return totalWeight;
}

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rankValue.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) {
            return false;
        }

        if (rankValue[rootA] < rankValue[rootB]) {
            parent[rootA] = rootB;
        } else if (rankValue[rootA] > rankValue[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rankValue[rootA]++;
        }
        return true;
    }
};

int kruskalMst(int vertices, vector<WeightedEdge> edges) {
    sort(edges.begin(), edges.end(), [](const WeightedEdge& a, const WeightedEdge& b) {
        return a.weight < b.weight;
    });

    DisjointSet dsu(vertices);
    int totalWeight = 0;

    cout << "\nKruskal MST edges:\n";
    for (WeightedEdge edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            totalWeight += edge.weight;
            cout << edge.u << " - " << edge.v << " weight " << edge.weight << "\n";
        }
    }

    return totalWeight;
}

void addWeightedUndirectedEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

int main() {
    cout << "GRAPH ALGORITHMS DEMONSTRATION\n";
    cout << "================================\n";

    vector<vector<int>> undirected(6);
    addUndirectedEdge(undirected, 0, 1);
    addUndirectedEdge(undirected, 1, 2);
    addUndirectedEdge(undirected, 2, 0);
    addUndirectedEdge(undirected, 3, 4);

    cout << "\nUndirected sample: triangle 0-1-2-0 and edge 3-4, vertex 5 alone.\n";
    printConnectedComponents(undirected);
    cout << "Undirected cycle exists: " << (hasUndirectedCycle(undirected) ? "Yes" : "No") << "\n";

    vector<vector<int>> directedCycle(4);
    addDirectedEdge(directedCycle, 0, 1);
    addDirectedEdge(directedCycle, 1, 2);
    addDirectedEdge(directedCycle, 2, 0);
    addDirectedEdge(directedCycle, 2, 3);
    cout << "\nDirected sample for cycle: 0->1->2->0 and 2->3\n";
    cout << "Directed cycle exists: " << (hasDirectedCycle(directedCycle) ? "Yes" : "No") << "\n";

    vector<vector<int>> dag(6);
    addDirectedEdge(dag, 5, 2);
    addDirectedEdge(dag, 5, 0);
    addDirectedEdge(dag, 4, 0);
    addDirectedEdge(dag, 4, 1);
    addDirectedEdge(dag, 2, 3);
    addDirectedEdge(dag, 3, 1);

    cout << "\nDAG sample edges: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1\n";
    vector<int> topo = topologicalSort(dag);
    cout << "Topological order: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << "\n";

    vector<vector<pair<int, int>>> weighted(5);
    vector<WeightedEdge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8},
        {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    for (WeightedEdge edge : edges) {
        addWeightedUndirectedEdge(weighted, edge.u, edge.v, edge.weight);
    }

    cout << "\nWeighted sample graph edges:\n";
    for (WeightedEdge edge : edges) {
        cout << edge.u << " - " << edge.v << " weight " << edge.weight << "\n";
    }

    vector<int> distances = dijkstra(weighted, 0);
    cout << "\nDijkstra shortest distances from 0:\n";
    for (int i = 0; i < (int)distances.size(); i++) {
        cout << "0 to " << i << " = " << distances[i] << "\n";
    }

    int primWeight = primMst(weighted);
    cout << "Prim MST total weight: " << primWeight << "\n";

    int kruskalWeight = kruskalMst(5, edges);
    cout << "Kruskal MST total weight: " << kruskalWeight << "\n";

    return 0;
}
