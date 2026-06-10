#include <bits/stdc++.h>
using namespace std;

/*
Quick Revision Templates - C++17
Condensed exam versions of: BFS, DFS, BST insert/delete/inorder,
Dijkstra, Prim, Kruskal, and AVL insert.
*/

void bfs(vector<vector<int>>& adj, int s) {
    vector<int> vis(adj.size(), 0);
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) if (!vis[v]) vis[v] = 1, q.push(v);
    }
}

void dfs(vector<vector<int>>& adj, int u, vector<int>& vis) {
    vis[u] = 1;
    cout << u << " ";
    for (int v : adj[u]) if (!vis[v]) dfs(adj, v, vis);
}

struct BstNode {
    int data;
    BstNode *left, *right;
    BstNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

BstNode* bstInsert(BstNode* root, int x) {
    if (!root) return new BstNode(x);
    if (x < root->data) root->left = bstInsert(root->left, x);
    else if (x > root->data) root->right = bstInsert(root->right, x);
    return root;
}

BstNode* bstMin(BstNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

BstNode* bstDelete(BstNode* root, int x) {
    if (!root) return nullptr;
    if (x < root->data) root->left = bstDelete(root->left, x);
    else if (x > root->data) root->right = bstDelete(root->right, x);
    else {
        if (!root->left) { BstNode* r = root->right; delete root; return r; }
        if (!root->right) { BstNode* l = root->left; delete root; return l; }
        BstNode* s = bstMin(root->right);
        root->data = s->data;
        root->right = bstDelete(root->right, s->data);
    }
    return root;
}

void inorder(BstNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
    const int INF = 1e9;
    vector<int> dist(adj.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) dist[v] = dist[u] + w, pq.push({dist[v], v});
        }
    }
    return dist;
}

int prim(vector<vector<pair<int, int>>>& adj) {
    vector<int> used(adj.size(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int total = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (used[u]) continue;
        used[u] = 1;
        total += w;
        for (auto [v, cost] : adj[u]) if (!used[v]) pq.push({cost, v});
    }
    return total;
}

struct Edge { int u, v, w; };
struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    DSU dsu(n);
    int total = 0;
    for (Edge e : edges) if (dsu.unite(e.u, e.v)) total += e.w;
    return total;
}

struct AvlNode {
    int data, h;
    AvlNode *left, *right;
    AvlNode(int x) : data(x), h(1), left(nullptr), right(nullptr) {}
};

int h(AvlNode* n) { return n ? n->h : 0; }
void upd(AvlNode* n) { n->h = 1 + max(h(n->left), h(n->right)); }
AvlNode* rotR(AvlNode* y) { AvlNode* x = y->left; y->left = x->right; x->right = y; upd(y); upd(x); return x; }
AvlNode* rotL(AvlNode* x) { AvlNode* y = x->right; x->right = y->left; y->left = x; upd(x); upd(y); return y; }

AvlNode* avlInsert(AvlNode* root, int x) {
    if (!root) return new AvlNode(x);
    if (x < root->data) root->left = avlInsert(root->left, x);
    else if (x > root->data) root->right = avlInsert(root->right, x);
    else return root;
    upd(root);
    int b = h(root->left) - h(root->right);
    if (b > 1 && x < root->left->data) return rotR(root);
    if (b < -1 && x > root->right->data) return rotL(root);
    if (b > 1) { root->left = rotL(root->left); return rotR(root); }
    if (b < -1) { root->right = rotR(root->right); return rotL(root); }
    return root;
}

int main() {
    vector<vector<int>> adj(4);
    adj[0] = {1, 2}; adj[1] = {0, 3}; adj[2] = {0}; adj[3] = {1};
    cout << "BFS: "; bfs(adj, 0); cout << "\nDFS: ";
    vector<int> vis(4, 0); dfs(adj, 0, vis); cout << "\n";

    BstNode* bst = nullptr;
    for (int x : {50, 30, 70, 20, 40}) bst = bstInsert(bst, x);
    cout << "BST inorder: "; inorder(bst); cout << "\n";
    bst = bstDelete(bst, 30);
    cout << "BST after delete 30: "; inorder(bst); cout << "\n";

    vector<vector<pair<int, int>>> weighted(3);
    weighted[0] = {{1, 4}, {2, 1}};
    weighted[1] = {{0, 4}, {2, 2}};
    weighted[2] = {{0, 1}, {1, 2}};
    cout << "Dijkstra 0 to 1: " << dijkstra(weighted, 0)[1] << "\n";
    cout << "Prim MST: " << prim(weighted) << "\n";
    cout << "Kruskal MST: " << kruskal(3, {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}}) << "\n";

    AvlNode* avl = nullptr;
    for (int x : {30, 20, 10}) avl = avlInsert(avl, x);
    cout << "AVL root after LL rotation: " << avl->data << "\n";

    return 0;
}
