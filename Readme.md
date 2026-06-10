# DSA Template Guide - C++17

Offline study templates for a national practical examination.

## How to Compile

```bash
g++ -std=c++17 path/to/file.cpp -o program
```

Example:

```bash
g++ -std=c++17 graph/03_graph_algorithms.cpp -o graph_algorithms
```

## Graph Templates

| File | Contents |
|------|----------|
| `graph/README.md` | Graph notes, analogies, operations, and study order |
| `graph/01_graph_representation.cpp` | Adjacency matrix and adjacency list |
| `graph/02_graph_traversal.cpp` | BFS, DFS recursive, DFS iterative |
| `graph/03_graph_algorithms.cpp` | Connected components, cycle detection, topological sort, Dijkstra, Prim, Kruskal |

Older practice files are still kept in `graph/` for reference.

## Linked List Templates

| File | Contents |
|------|----------|
| `linked_list/README.md` | Linked-list notes, scenarios, operation complexity |
| `linked_list/00_linked_list_full_notes.cpp` | Singly, doubly, circular lists, insert, delete, search, reverse, middle |

Older practice files are still kept in `linked_list/` for reference.

## Queue Templates

| File | Contents |
|------|----------|
| `queues/README.md` | Queue notes, FIFO analogy, operation complexity |
| `queues/00_queue_full_notes.cpp` | Circular queue, linked queue, priority queue |

Older practice files are still kept in `queues/` for reference.

## Sorting Templates

| File | Contents |
|------|----------|
| `sorting/README.md` | Sorting notes, algorithm comparison, exam clues |
| `sorting/00_sorting_full_notes.cpp` | Bubble, selection, insertion, merge, quick, heap sort |

Older practice files are still kept in `sorting/` for reference.

## Stack Templates

| File | Contents |
|------|----------|
| `stack/README.md` | Stack notes, LIFO analogy, operation complexity |
| `stack/00_stack_full_notes.cpp` | Array stack, linked stack, balanced parentheses, string reverse |

Older practice files are still kept in `stack/` for reference.

## Tree Templates

| File | Contents |
|------|----------|
| `trees/README.md` | Tree notes, analogies, operations, and study order |
| `trees/01_binary_tree_and_traversals.cpp` | Manual binary tree insertion and traversals |
| `trees/02_binary_search_tree_full.cpp` | BST insert, search, delete, min, max, validity |
| `trees/03_avl_tree.cpp` | AVL rotations, insert with balancing, search |
| `trees/04_heap_tree.cpp` | Max heap, min heap, insert, delete root, heapify |
| `trees/05_tree_utilities.cpp` | Height, count nodes, count leaves, mirror, BST check |

Older practice files are still kept in `trees/` for reference.

## Exam Ready

| File | Contents |
|------|----------|
| `exam_ready/quick_revision_templates.cpp` | Condensed BFS, DFS, BST insert/delete, inorder, Dijkstra, Prim, Kruskal, AVL insert |

## National Exam Style Questions

The `exam_questions/` folder contains ten complete runnable C++17 solutions:

1. Build a BST and perform traversals.
2. Find shortest paths in a weighted graph.
3. Detect a cycle in an undirected graph.
4. Implement heap operations.
5. Count leaf nodes.
6. Topologically sort dependent tasks.
7. Count connected components.
8. Find an MST using Prim.
9. Find an MST using Kruskal.
10. Insert and search in an AVL tree.

## Recommended Study Path

1. Read each folder `README.md`.
2. Run the `00_*_full_notes.cpp` files for linked list, queue, sorting, and stack.
3. Run the numbered graph and tree files.
4. Use `exam_ready/quick_revision_templates.cpp` for memorization.
5. Solve the files in `exam_questions/` without looking at the solutions first.
