#include <iostream>
#include <vector>
using namespace std;

/*
Purpose:
    Implement Max Heap and Min Heap using arrays.
    Heap is a complete binary tree stored level-order in a vector.

Example max heap:
            50
          /    \
        30      40
       /  \
     10   20

Index formulas:
    parent(i) = (i - 1) / 2
    left(i) = 2 * i + 1
    right(i) = 2 * i + 2

Time complexity:
    Insert: O(log n)
    Delete root: O(log n)
    Heapify: O(log n)
    Build by repeated insert: O(n log n)

Space complexity:
    O(n)
*/

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] >= heap[index]) {
                break;
            }
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();

        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest == index) {
                break;
            }

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int deleteRoot() {
        if (heap.empty()) {
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }

        return root;
    }

    void print() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << "\n";
    }
};

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] <= heap[index]) {
                break;
            }
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();

        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < n && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest == index) {
                break;
            }

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int deleteRoot() {
        if (heap.empty()) {
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }

        return root;
    }

    void print() const {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << "\n";
    }
};

int main() {
    int values[] = {10, 30, 20, 50, 40};

    cout << "Insert values: 10, 30, 20, 50, 40\n\n";

    MaxHeap maxHeap;
    MinHeap minHeap;

    for (int value : values) {
        maxHeap.insert(value);
        minHeap.insert(value);
    }

    cout << "Max heap array before delete root: ";
    maxHeap.print();
    cout << "Delete max/root: " << maxHeap.deleteRoot() << "\n";
    cout << "Max heap array after delete root: ";
    maxHeap.print();

    cout << "\nMin heap array before delete root: ";
    minHeap.print();
    cout << "Delete min/root: " << minHeap.deleteRoot() << "\n";
    cout << "Min heap array after delete root: ";
    minHeap.print();

    return 0;
}
