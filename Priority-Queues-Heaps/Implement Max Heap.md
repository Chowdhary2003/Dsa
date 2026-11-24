***Problem:***
```
You need to implement the Max Heap with the following given methods.

- insert (x) -> insert value x to the max heap
- getMax -> Output the maximum value from the max heap
- exctractMax -> Remove the maximum element from the heap
- heapSize -> return the current size of the heap
- isEmpty -> returns if heap is empty or not
- changeKey (ind, val) -> update the value at given index to val (index will be given 0-based indexing)
- initializeHeap -> Initialize the heap
```



***Complexity:***
```
       Time Complexity: 
       Space Complexity:

| Operation          | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| `insert(x)`        | O(log n)        | O(n)             |
| `getMax()`         | O(1)            | O(1)             |
| `extractMax()`     | O(log n)        | O(1)             |
| `changeKey(i,v)`   | O(log n)        | O(1)             |
| `heapSize()`       | O(1)            | O(1)             |
| `isEmpty()`        | O(1)            | O(1)             |
| `initializeHeap()` | O(1)            | O(1)             |
```



***Code:***
```cpp
#include <vector>
#include <stdexcept>
#include <iostream>

class MaxHeap {
private:
    std::vector<int> heap;

    // Helper: Get parent/child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Heapify up: fix heap property upwards
    void heapifyUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify down: fix heap property downwards
    void heapifyDown(int i) {
        int size = heap.size();
        while (true) {
            int largest = i;
            int l = left(i), r = right(i);
            if (l < size && heap[l] > heap[largest]) largest = l;
            if (r < size && heap[r] > heap[largest]) largest = r;

            if (largest == i) break;
            std::swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void initializeHeap() {
        heap.clear();
    }

    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int getMax() const {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        return heap[0];
    }

    void extractMax() {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
    }

    int heapSize() const {
        return heap.size();
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void changeKey(int index, int newVal) {
        if (index < 0 || index >= heap.size())
            throw std::out_of_range("Invalid index");

        int oldVal = heap[index];
        heap[index] = newVal;

        if (newVal > oldVal)
            heapifyUp(index);
        else if (newVal < oldVal)
            heapifyDown(index);
        // if equal, no action needed
    }
};
```


***Testcases:***
```
Input : operation = [ "initializeHeap", "insert", "insert", "insert", "getMax", "heapSize", "isEmpty", "exctractMax", "changeKey" , "getMax" ]

nums = [ [4], [1], [10], [0, 16] ]

Output : [ null, null, null, null, 10, 3, 0, null, null, 16 ]

Explanation : In 1st operation we initialize the heap to empty heap.

In 2nd, 3rd, 4th operation we insert 4, 1, 10 to the heap respectively. The heap after 4th operation will be -> [10, 4, 1].

In 5th operation we output the maximum element from the heap i.e. 10.

In 6th operation we output the size of the current heap i.e. 3.

In 7th operation we output whether the heap is empty or not i.e. false (0).

In 8th operation we remove the maximum element from heap. So the ne heap becomes -> [4, 1].

In 9th operation we change the 0th index element to 16. So new heap becomes -> [16, 1]. After heapify -> [16, 1].

In 10th operation we output the maximum element of the heap i.e. 16.
```

```
Input : operation = [ "initializeHeap", "insert", "insert", "exctractMax", "getMax", "insert", "heapSize", "isEmpty", "exctractMax", "changeKey" , "getMax" ]

nums = [ [4], [1], [4], [0, 2] ]

Output : [ null, null, null, null, 1, null, 2, 0, null, null, 2 ]

Explanation : In 1st operation we initialize the heap to empty heap.

In 2nd, 3rd operation we insert 4, 1 to the heap respectively. The heap after 4th operation will be -> [4, 1].

In 4th operation we remove the maximum element from heap. So the ne heap becomes -> [1].

In 5th operation we output the maximum element of the heap i.e. 1.

In 6th operation we operation we insert 4 to the heap. The heap after 6th operation will be -> [4, 1].

In 7th operation we output the size of the current heap i.e. 2.

In 8th operation we output whether the heap is empty or not i.e. false (0).

In 9th operation we remove the maximum element from heap. So the ne heap becomes -> [1].

In 10th operation we change the 0th index element to 2. So new heap becomes -> [2].

In 11th operation we output the maximum element of the heap i.e. 2.
```
