***Problem:***
```
You are given k sorted arrays, each of size k. Merge all the arrays into one sorted array and return it.

You should use an efficient algorithm with O(k² log k) time complexity.
```



***Complexity:***
```
       Time Complexity: O(k^2 log k)
       Space Complexity: O(𝑘^2), O(𝑘)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    int k = arrays.size();
    if (k == 0) return {};

    // Min-heap element: tuple(value, array_index, element_index)
    using Element = tuple<int, int, int>;
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Initialize heap with first element of each array
    for (int i = 0; i < k; ++i) {
        if (!arrays[i].empty()) {
            minHeap.emplace(arrays[i][0], i, 0);
        }
    }

    vector<int> merged;
    merged.reserve(k * k);

    while (!minHeap.empty()) {
        auto [val, arrIdx, elemIdx] = minHeap.top();
        minHeap.pop();
        merged.push_back(val);

        // If there is a next element in the same array, push it into the heap
        if (elemIdx + 1 < (int)arrays[arrIdx].size()) {
            minHeap.emplace(arrays[arrIdx][elemIdx + 1], arrIdx, elemIdx + 1);
        }
    }

    return merged;
}
```


***Testcases:***
```
Input: k = 3, arr = [[1,2,3],[4,5,6],[7,8,9]]

Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

```
Input: k = 4, arr = [[1,2,3,4],[2,2,3,4],[5,5,6,6],[7,8,9,9]]

Output: [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9]
```
