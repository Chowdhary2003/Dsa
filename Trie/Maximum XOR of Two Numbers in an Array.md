***Problem:***
```
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
```



***Complexity:***
```
       Time Complexity: O(32 * n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int findMaximumXOR(const vector<int>& nums) {
        int maxXor = 0, mask = 0;

        // Check from the highest bit to the lowest
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);  // Add current bit to mask

            std::unordered_set<int> prefixes;
            for (int num : nums) {
                prefixes.insert(num & mask);  // Store masked prefix
            }

            // Try to set the current bit in maxXor
            int candidate = maxXor | (1 << i);
            bool found = false;

            for (int prefix : prefixes) {
                if (prefixes.count(prefix ^ candidate)) {
                    found = true;
                    break;
                }
            }

            if (found) {
                maxXor = candidate;
            }
        }

        return maxXor;
    }
};
```


***Testcases:***
```
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
```

```
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
```
