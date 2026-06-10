# Tree Notes

Analogy: a tree is like a family tree or school hierarchy. One root branches into children.

Use trees when data has hierarchy, sorted search structure, or priority relationships.

## Core Operations

| Topic | Operations | Typical Complexity |
|-------|------------|--------------------|
| Binary tree | Manual linking and traversals | `O(n)` traversal |
| BST | Insert, search, delete, min, max | Average `O(log n)`, worst `O(n)` |
| AVL | Rotations, balanced insert/search | `O(log n)` |
| Heap | Insert, delete root, heapify | `O(log n)` |
| Utilities | Height, count nodes, leaves, mirror, check BST | `O(n)` |

## Study Order

1. `01_binary_tree_and_traversals.cpp`
2. `02_binary_search_tree_full.cpp`
3. `03_avl_tree.cpp`
4. `04_heap_tree.cpp`
5. `05_tree_utilities.cpp`

Exam clue: inorder traversal of a valid BST prints values in sorted order.
