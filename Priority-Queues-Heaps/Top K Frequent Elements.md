***Problem:***
```
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
```



***Complexity:***
```
       Time Complexity: O(n + U log k)
       Space Complexity: O(U + k) ≈ O(n) in worst case.
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>      // for std::pair
#include <functional>   // for std::greater
#include <iostream>

using namespace std;

vector<int> topKFrequent(const vector<int>& nums, int k) {
    // Step 1: Count frequencies
    unordered_map<int, int> freq;
    for (int num : nums) {
        ++freq[num];
    }

    // Step 2: Min-heap to store top k elements by frequency
    using Entry = pair<int, int>; // {frequency, number}
    priority_queue<Entry, vector<Entry>, greater<>> minHeap;

    for (const auto& [num, count] : freq) {
        minHeap.emplace(count, num);
        if (minHeap.size() > k) {
            minHeap.pop(); // Keep only top k
        }
    }

    // Step 3: Extract results
    vector<int> result;
    result.reserve(k); // Avoid unnecessary reallocations
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result; // Order doesn't matter
}
```


***Testcases:***
```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

```
Input: nums = [1], k = 1
Output: [1]
```

```
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [-1]
```
