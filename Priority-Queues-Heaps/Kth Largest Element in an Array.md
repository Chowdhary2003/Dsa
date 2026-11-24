***Problem:***
```
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
```



***Complexity:***
```
       Time Complexity: O(n log k)
       Space Complexity: O(k)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <functional>

int findKthLargest(const std::vector<int>& nums, int k) {
    // Min-heap to store the k largest elements
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;

    for (int num : nums) {
        minHeap.push(num); // Add the current number
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove the smallest among the k+1 elements
        }
    }

    // Top of the heap is the k-th largest element
    return minHeap.top();
}
```


***Testcases:***
```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```

```
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```
