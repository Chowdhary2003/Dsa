***Problem:***
```
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
    // Step 1: Sort envelopes
    std::sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
        if (a[0] == b[0])
            return a[1] > b[1]; // Descending height if widths are equal
        return a[0] < b[0];     // Ascending width
    });

    // Step 2: Extract heights
    std::vector<int> heights;
    for (const auto& env : envelopes) {
        heights.push_back(env[1]);
    }

    // Step 3: Perform LIS on heights
    std::vector<int> dp;
    for (int h : heights) {
        auto it = std::lower_bound(dp.begin(), dp.end(), h);
        if (it == dp.end()) {
            dp.push_back(h);
        } else {
            *it = h; // Replace with smaller value
        }
    }

    return dp.size(); // Length of LIS
}
```


***Testcases:***
```
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
```

```
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
```
