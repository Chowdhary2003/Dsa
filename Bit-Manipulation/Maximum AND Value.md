***Problem:***
```
Given an array arr[] of positive integers, You have to find the maximum AND value obtained by any pair (arr[i], arr[j]) such that i ≠ j .
   Note: AND is bitwise '&' operator.
```



***Complexity:***
```
       Time Complexity: O(32 * n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 🧰 Function to compute max AND value among all pairs
int maxANDValue(const vector<int>& arr) {
    int result = 0;
    vector<int> candidates = arr;

    // Try setting bits from MSB (31) down to 0
    for (int bit = 31; bit >= 0; --bit) {
        int testBit = result | (1 << bit);

        // Filter numbers that can potentially contribute to this bit
        vector<int> filtered;
        for (int num : candidates) {
            if ((num & testBit) == testBit) {
                filtered.push_back(num);
            }
        }

        if (filtered.size() >= 2) {
            // At least one valid pair found with this bit set
            result = testBit;
            candidates = move(filtered);  // shrink candidate pool
        }
        // else: not enough support to keep this bit, skip it
    }

    return result;
}
```


***Testcases:***
```
Input: arr[] = [4, 8, 12, 16]
Output: 8
Explanation: Pair (8,12) has the maximum AND value 0.
```

```
Input: arr[] = [4, 8, 16, 2]
Output: 0
Explanation: All pairwise AND values are 0, so the maximum possible AND value among them is also 0.
```
