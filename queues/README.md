# Queue Notes

Analogy: a queue is a bank line. First person in is first person served.

Queue rule: FIFO, First In First Out.

## Core Operations

| Operation | Meaning | Complexity |
|-----------|---------|------------|
| Enqueue | Insert at rear | `O(1)` |
| Dequeue | Remove from front | `O(1)` |
| Front | Read next item to leave | `O(1)` |
| Rear | Read last inserted item | `O(1)` |
| isEmpty | Check underflow risk | `O(1)` |
| isFull | Check overflow risk in arrays | `O(1)` |

Open first: `00_queue_full_notes.cpp`.

Exam clue: BFS uses a queue because it explores neighbours level by level.
