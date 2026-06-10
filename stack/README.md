# Stack Notes

Analogy: a stack is a pile of plates. The last plate placed on top is the first one removed.

Stack rule: LIFO, Last In First Out.

## Core Operations

| Operation | Meaning | Complexity |
|-----------|---------|------------|
| Push | Add to top | `O(1)` |
| Pop | Remove from top | `O(1)` |
| Top/Peek | Read top item | `O(1)` |
| isEmpty | Check underflow risk | `O(1)` |
| isFull | Check overflow risk in arrays | `O(1)` |

Open first: `00_stack_full_notes.cpp`.

Exam clue: balanced parentheses, undo operations, and recursion simulation usually need a stack.
