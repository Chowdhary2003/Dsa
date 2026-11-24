***Problem:***
```
Given an integer array nums, return the length of the longest strictly increasing subsequence.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // for std::lower_bound

class Solution {
public:
    int lengthOfLIS(const std::vector<int>& nums) {
        std::vector<int> tails;  // tails[i] = smallest tail of LIS with length i+1

        for (int num : nums) {
            // Find insertion point via binary search
            auto it = std::lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                // num is greater than all tails, extend LIS
                tails.push_back(num);
            } else {
                // Replace existing tail to maintain minimal tails
                *it = num;
            }
        }

        return static_cast<int>(tails.size());
    }
};
```


***Testcases:***
```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

```
Input: nums = [0,1,0,3,2,3]
Output: 4
```

```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```
