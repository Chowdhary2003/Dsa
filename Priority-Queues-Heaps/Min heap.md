# Min heap

## Problem statement

> **Inferred summary:** Implement a min-heap supporting insertion, removal of the minimum element, and an emptiness check.
>
> The original C++ file did not include a complete problem statement; this summary is inferred from the file name and implementation.

## C++ implementation

```cpp
class MinHeap {

private:

    std::vector<int> heap;

    // Helper function to maintain the min heap property by moving an element up the heap

    void heapifyUp(int index) {

        while (index > 0) {

            int parentIndex = (index - 1) / 2;

            if (heap[parentIndex] > heap[index]) {

                std::swap(heap[parentIndex], heap[index]);

                index = parentIndex;

            } else {

                break;

            }

        }

    }

    // Helper function to maintain the min heap property by moving an element down the heap

    void heapifyDown(int index) {

        int size = heap.size();

        while (true) {

            int leftChildIndex = 2 * index + 1;

            int rightChildIndex = 2 * index + 2;

            int smallestIndex = index;

            if (leftChildIndex < size && heap[leftChildIndex] < heap[smallestIndex]) {

                smallestIndex = leftChildIndex;

            }

            if (rightChildIndex < size && heap[rightChildIndex] < heap[smallestIndex]) {

                smallestIndex = rightChildIndex;

            }

            if (smallestIndex != index) {

                std::swap(heap[index], heap[smallestIndex]);

                index = smallestIndex;

            } else {

                break;

            }

        }

    }

public:

    // Insert an element into the min heap

    void insert(int value) {

        heap.push_back(value);

        heapifyUp(heap.size() - 1);

    }

    // Remove and return the minimum element from the min heap

    int removeMin() {

        if (heap.empty()) {

            throw std::out_of_range("Heap is empty");

        }

        int minValue = heap.front();

        std::swap(heap.front(), heap.back());

        heap.pop_back();

        heapifyDown(0);

        return minValue;

    }

    // Check if the min heap is empty

    bool isEmpty() {

        return heap.empty();

    }

};
```
