***Problem:***
```
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
```



***Complexity:***
```
       Time Complexity: O(n * sum(nums)/2)
       Space Complexity: O(target)
```



***Code:***
```cpp
#include <vector>
#include <numeric>  // for std::accumulate

class Solution {
public:
    bool canPartition(const std::vector<int>& nums) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        // If total sum is odd, can't split equally
        if (total_sum % 2 != 0) return false;

        int target = total_sum / 2;
        // dp[s] = whether a subset with sum s is achievable
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;  // zero sum is always achievable (empty subset)

        for (int num : nums) {
            // Traverse backwards to avoid using the same element multiple times
            for (int s = target; s >= num; --s) {
                dp[s] = dp[s] || dp[s - num];
            }
            if (dp[target]) return true;  // early exit optimization
        }

        return dp[target];
    }
};
```


***Testcases:***
```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
```

```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
```
