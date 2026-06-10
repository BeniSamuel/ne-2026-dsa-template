# Graph Notes

Analogy: a graph is like a map of towns and roads. Vertices are towns; edges are roads.

Use graphs when a problem talks about connections, routes, networks, dependencies, or relationships.

## Core Operations

| Operation | Meaning | Typical Complexity |
|-----------|---------|--------------------|
| Add vertex | Add a new point/node | Depends on representation |
| Add edge | Connect two vertices | `O(1)` in adjacency list push |
| Check edge | Ask whether `u` connects to `v` | Matrix `O(1)`, list `O(degree)` |
| BFS | Visit level by level | `O(V + E)` |
| DFS | Visit deeply before backtracking | `O(V + E)` |
| Connected components | Find separate groups | `O(V + E)` |
| Cycle detection | Check whether a loop exists | `O(V + E)` |
| Topological sort | Order dependency tasks | `O(V + E)` |
| Dijkstra | Shortest path with non-negative weights | `O((V + E) log V)` |
| Prim/Kruskal | Minimum spanning tree | `O(E log V)` or `O(E log E)` |

## Study Order

1. `01_graph_representation.cpp`
2. `02_graph_traversal.cpp`
3. `03_graph_algorithms.cpp`

Exam clue: if the question says shortest path with positive weights, think Dijkstra. If it says connect all places with minimum cost, think MST using Prim or Kruskal.
