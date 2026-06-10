# Sorting Notes

Analogy: sorting is arranging students by marks, height, or roll number.

## Core Algorithms

| Algorithm | Best For | Time |
|-----------|----------|------|
| Bubble sort | Learning swaps | `O(n^2)` |
| Selection sort | Simple minimum selection | `O(n^2)` |
| Insertion sort | Small or almost sorted input | Best `O(n)`, worst `O(n^2)` |
| Merge sort | Guaranteed efficient sorting | `O(n log n)` |
| Quick sort | Fast average practical sorting | Average `O(n log n)` |
| Heap sort | In-place `O(n log n)` sorting | `O(n log n)` |

Open first: `00_sorting_full_notes.cpp`.

Exam clue: if the question asks you to show passes, bubble/selection/insertion are easier. If it asks for efficient sorting, use merge, quick, or heap sort.
