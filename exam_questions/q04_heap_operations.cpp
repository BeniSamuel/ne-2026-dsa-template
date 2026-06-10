#include <iostream>
#include <vector>
using namespace std;

/*
Question:
    Implement a max heap and perform insert and delete root.

Requirements:
    Insert 10, 30, 20, 50, 40. Delete the maximum element.

Strategy:
    Store heap in an array. Move inserted value up while it is larger
    than its parent. After deleting root, move the replacement down.

Complexity:
    Insert O(log n), delete root O(log n), space O(n).
*/

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] >= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int deleteRoot() {
        if (heap.empty()) return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return root;
    }

    void print() {
        for (int value : heap) cout << value << " ";
        cout << "\n";
    }
};

int main() {
    MaxHeap heap;
    for (int value : {10, 30, 20, 50, 40}) heap.insert(value);
    cout << "Heap before delete: "; heap.print();
    cout << "Deleted root: " << heap.deleteRoot() << "\n";
    cout << "Heap after delete: "; heap.print();
    return 0;
}
