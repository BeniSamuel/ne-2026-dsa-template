# Linked List Notes

Analogy: a linked list is a chain of cards. Each card stores data and points to the next card.

Use linked lists when insertion and deletion are more important than direct indexing.

## Core Operations

| Operation | Meaning | Complexity |
|-----------|---------|------------|
| Insert front | Add before current head | `O(1)` |
| Insert back | Add after last node | `O(n)` without tail, `O(1)` with tail |
| Insert position | Add at a given rank | `O(n)` |
| Delete front | Remove head | `O(1)` |
| Delete back | Remove tail | `O(n)` without previous/tail support |
| Delete value | Remove first matching node | `O(n)` |
| Search | Find a value | `O(n)` |
| Reverse | Turn all links backward | `O(n)` |
| Middle node | Slow/fast pointer method | `O(n)` |

Open first: `00_linked_list_full_notes.cpp`.

Exam clue: linked-list mistakes usually happen when updating pointers. Always keep a temporary pointer before deleting a node.
