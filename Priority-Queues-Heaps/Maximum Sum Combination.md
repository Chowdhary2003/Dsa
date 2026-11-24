***Problem:***
```
Given two integer arrays nums1 and nums2 and an integer k, return the maximum k valid sum combinations from all possible sum combinations using the elements of nums1 and nums2.

A valid sum combination is made by adding one element from nums1 and one element from nums2. Return the answer in non-increasing order.
```



***Complexity:***
```
       Time Complexity: O((n + m) log n + k log k)
       Space Complexity: O(k)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> maxKSumCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
    // Sort both arrays in descending order to start from largest possible sums
    sort(nums1.rbegin(), nums1.rend());
    sort(nums2.rbegin(), nums2.rend());

    using T = tuple<int, int, int>; // (sum, i, j)

    // Max heap to always extract current max sum
    priority_queue<T> maxHeap;

    set<pair<int, int>> visited; // To avoid duplicate pairs

    int n = nums1.size();
    int m = nums2.size();

    // Start with the largest sum
    maxHeap.emplace(nums1[0] + nums2[0], 0, 0);
    visited.emplace(0, 0);

    vector<int> result;

    while (k-- && !maxHeap.empty()) {
        auto [sum, i, j] = maxHeap.top();
        maxHeap.pop();
        result.push_back(sum);

        // Move to next in nums1
        if (i + 1 < n && !visited.count({i + 1, j})) {
            maxHeap.emplace(nums1[i + 1] + nums2[j], i + 1, j);
            visited.emplace(i + 1, j);
        }

        // Move to next in nums2
        if (j + 1 < m && !visited.count({i, j + 1})) {
            maxHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            visited.emplace(i, j + 1);
        }
    }

    return result;
}
```


***Testcases:***
```
Input: nums1 = [7, 3], nums2 = [1, 6], k = 2

Output: [13, 9]

Explanation: The 2 maximum combinations are made by:

nums1[0] + nums2[1] = 13

nums1[1] + nums2[1] = 9
```

```
Input: nums1 = [3, 4, 5], nums2 = [2, 6, 3], k = 2

Output: [11, 10]

Explanation: The 2 maximum combinations are made by:

nums1[2] + nums2[1] = 11

nums1[1] + nums2[1] = 10
```
