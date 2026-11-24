***Problem:***
```
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.
```



***Complexity:***
```
       Time Complexity: O(N^2)
       Space Complexity: O(N)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<int> dp(n, 1);  // dp[i] will store the length of LIS ending at index i
        vector<int> count(n, 1);  // count[i] will store the number of LIS ending at index i

        int maxLen = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {  // strictly increasing condition
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];  // reset count[i] to count[j]
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];  // add count[j] to count[i]
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxLen) {
                result += count[i];
            }
        }

        return result;
    }
};
```


***Testcases:***
```
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
```

```
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
```
