# Implement a priority queue

## Problem statement

> **Inferred summary:** Implement a max-priority queue using a vector-backed binary heap. Support insertion with `push` and removal of the maximum element with `pop`.
>
> The original C++ file did not include a complete problem statement; this summary is inferred from the file name and implementation.

## C++ implementation

```cpp
/*
    Time Complexity: O(log(N)) for push and pop
    Space Complexity: O(1)

    where 'N' is the size of the heap.
*/

void push(vector<int> &heap, int x)
{
    heap.push_back(x);
    int pos = heap.size() - 1;

    while (pos > 0)
    {
        int parent = (pos - 1) / 2;
        if (heap[pos] > heap[parent])
        {
            swap(heap[parent], heap[pos]);
            pos = parent;
        }
        else
        {
            break;
        }
    }
}

int pop(vector<int> &heap)
{
    if (heap.size() == 0)
        return -1;
    int ans = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    if (heap.size() == 0)
        return ans;
    
    int pos = 0;
    while (true)
    {
        int left = pos * 2 + 1;
        int right = pos * 2 + 2;
        int leftValue = (left < heap.size()) ? heap[left] : INT_MIN;
        int rightValue = (right < heap.size()) ? heap[right] : INT_MIN;

        if (leftValue <= heap[pos] && rightValue <= heap[pos])
        {
            break;
        }
        else if (leftValue >= rightValue)
        {
            swap(heap[pos], heap[left]);
            pos = left;
        }
        else
        {
            swap(heap[pos], heap[right]);
            pos = right;
        }
    }
    return ans;
}
```
