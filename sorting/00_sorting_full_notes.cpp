#include <iostream>
using namespace std;

/*
SORTING FULL NOTES - C++17

Analogy:
    Sorting is arranging students by height, marks, or roll number.
    Different sorting algorithms use different strategies:
        Bubble: repeatedly swap neighbours that are in the wrong order.
        Selection: repeatedly select the smallest remaining item.
        Insertion: insert each item into the sorted left part.
        Merge: split into halves, sort, then merge.
        Quick: choose a pivot and partition smaller/larger values.
        Heap: build a heap and repeatedly remove the largest.

Exam scenarios:
    - Sort marks before finding rank.
    - Sort names or ids before searching.
    - Understand time complexity tradeoffs.

Complexity summary:
    Bubble sort: O(n^2), space O(1), stable
    Selection sort: O(n^2), space O(1), not stable in normal form
    Insertion sort: O(n^2), best O(n), space O(1), stable
    Merge sort: O(n log n), space O(n), stable
    Quick sort: average O(n log n), worst O(n^2), space O(log n)
    Heap sort: O(n log n), space O(1), not stable
*/

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void copyArray(const int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

// Bubble Sort
// Scenario: Compare neighbouring students and swap if the taller one
// should stand later. Largest value bubbles to the end each pass.
void bubbleSort(int arr[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        bool swapped = false;

        for (int i = 0; i < n - pass - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

// Selection Sort
// Scenario: Pick the smallest remaining mark and put it in the next
// correct position.
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
// Scenario: Sort playing cards in your hand by inserting each new card
// into the already sorted left side.
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void mergeParts(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

// Merge Sort
// Scenario: Split a big class list into smaller lists, sort each small
// list, then combine the sorted lists.
void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeParts(arr, left, mid, right);
}

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];
    int smallerIndex = low - 1;

    for (int current = low; current < high; current++) {
        if (arr[current] <= pivot) {
            smallerIndex++;
            swap(arr[smallerIndex], arr[current]);
        }
    }

    swap(arr[smallerIndex + 1], arr[high]);
    return smallerIndex + 1;
}

// Quick Sort
// Scenario: Choose one student as pivot; shorter/equal students go left,
// taller students go right. Repeat for both sides.
void quickSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int pivotIndex = partitionArray(arr, low, high);
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

void heapify(int arr[], int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
// Scenario: First build a max heap so the largest mark is at the root.
// Move it to the end, reduce heap size, and heapify again.
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int end = n - 1; end > 0; end--) {
        swap(arr[0], arr[end]);
        heapify(arr, end, 0);
    }
}

void runSortDemo(const string& name, void (*sortFunction)(int[], int), const int original[], int n) {
    int arr[20];
    copyArray(original, arr, n);
    sortFunction(arr, n);
    cout << name << ": ";
    printArray(arr, n);
}

void runMergeSortDemo(const int original[], int n) {
    int arr[20];
    copyArray(original, arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Merge sort: ";
    printArray(arr, n);
}

void runQuickSortDemo(const int original[], int n) {
    int arr[20];
    copyArray(original, arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Quick sort: ";
    printArray(arr, n);
}

int main() {
    int original[] = {64, 25, 12, 22, 11, 90, 34};
    int n = sizeof(original) / sizeof(original[0]);

    cout << "Original marks: ";
    printArray(original, n);

    runSortDemo("Bubble sort", bubbleSort, original, n);
    runSortDemo("Selection sort", selectionSort, original, n);
    runSortDemo("Insertion sort", insertionSort, original, n);
    runMergeSortDemo(original, n);
    runQuickSortDemo(original, n);
    runSortDemo("Heap sort", heapSort, original, n);

    cout << "\nWhen to choose:\n";
    cout << "Insertion sort: small or almost sorted arrays.\n";
    cout << "Merge sort: guaranteed O(n log n), useful for linked lists.\n";
    cout << "Quick sort: usually fast in practice.\n";
    cout << "Heap sort: O(n log n) with O(1) extra array space.\n";

    return 0;
}
