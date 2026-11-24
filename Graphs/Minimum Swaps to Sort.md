***Problem:***
```
Given an array arr[] of distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
```



***Complexity:***
```
       Time Complexity: O(N log N)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // for iota
#include <unordered_map>

int minSwapsToSort(const std::vector<int>& arr) {
    int n = (int)arr.size();
    if (n <= 1) return 0;

    // Pair each element with its index
    std::vector<std::pair<int, int>> sortedArr(n);
    for (int i = 0; i < n; ++i)
        sortedArr[i] = {arr[i], i};

    // Sort by element value
    std::sort(sortedArr.begin(), sortedArr.end(), 
              [](auto& a, auto& b) { return a.first < b.first; });

    // Visited array to track cycles
    std::vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; ++i) {
        // Already visited or already in correct place
        if (visited[i] || sortedArr[i].second == i)
            continue;

        // Detect cycle size
        int cycleSize = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = sortedArr[j].second;  // Move to next index in cycle
            ++cycleSize;
        }

        // Add (cycleSize - 1) swaps for this cycle
        if (cycleSize > 1)
            swaps += (cycleSize - 1);
    }

    return swaps;
}
```


***Testcases:***
```
Input: arr[] = [2, 8, 5, 4]
Output: 1
Explanation: Swap 8 with 4 to get the sorted array.
```

```
Input: arr[] = [10, 19, 6, 3, 5]
Output: 2
Explanation: Swap 10 with 3 and 19 with 5 to get the sorted array.
```

```
Input: arr[] = [1, 3, 4, 5, 6]
Output: 0
Explanation: Input array is already sorted.
```
