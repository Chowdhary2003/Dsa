# Connect N Ropes With Minimum Cost

## Problem statement

> **Inferred summary:** Given the lengths of ropes, repeatedly connect the two shortest ropes. The cost of each connection is the sum of their lengths; return the minimum total cost needed to connect all ropes.
>
> The original C++ file did not include a complete problem statement; this summary is inferred from the file name and implementation.

## C++ implementation

```cpp
/*
    Time Complexity : O(N * log(N))
    Space Complexity : O(N)

    where N is the number of ropes given initially
*/

#include <queue>
#include <vector>

int connectRopes(int *arr, int n)
{
    // Initialize final cost variable
    int finalCost = 0;

    // Declaring a minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Inserting all ropes to the minHeap
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }

    // Merge until there is only one rope left in minHeap
    while (minHeap.size() > 1)
    {
        // Extract the smallest rope
        int smallest = minHeap.top();
        minHeap.pop();

        // Extract the second smallest rope
        int secondSmallest = minHeap.top();
        minHeap.pop();

        // Add cost of merging these two ropes to final answer
        finalCost += (smallest + secondSmallest);

        // Insert the combined rope back in the minHeap
        minHeap.push(smallest + secondSmallest);
    }

    // Return the finalCost
    return finalCost;
}
```
