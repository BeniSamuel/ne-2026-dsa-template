#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/*
Question:
    Find the minimum spanning tree cost using Kruskal's algorithm.

Requirements:
    Sort edges by weight and avoid cycles.

Strategy:
    Use Disjoint Set Union to check whether an edge connects two
    different components.

Complexity:
    Time O(E log E), space O(V).
*/

struct Edge {
    int u;
    int v;
    int w;
};

class DSU {
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    DSU(int n) {
        parent.resize(n);
        rankValue.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rankValue[a] < rankValue[b]) swap(a, b);
        parent[b] = a;
        if (rankValue[a] == rankValue[b]) rankValue[a]++;
        return true;
    }
};

int kruskal(int vertices, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu(vertices);
    int total = 0;

    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
            cout << "Take edge " << e.u << "-" << e.v << " weight " << e.w << "\n";
        }
    }

    return total;
}

int main() {
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8},
        {1, 4, 5}, {2, 4, 7}, {3, 4, 9}
    };

    cout << "Kruskal MST total cost: " << kruskal(5, edges) << "\n";
    return 0;
}
