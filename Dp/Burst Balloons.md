***Problem:***
```
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.
```



***Complexity:***
```
       Time Complexity: O(n³)
       Space Complexity: O(n²) for dp table, O(n) for augmented array val
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxCoins(const std::vector<int>& nums) {
        const size_t n = nums.size();

        // Augment the input array with virtual balloons having value 1 at both ends
        std::vector<int> balloons(n + 2, 1);
        for (size_t i = 0; i < n; ++i) {
            balloons[i + 1] = nums[i];
        }

        // dp[i][j] stores max coins from bursting balloons strictly between i and j
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

        // Consider subintervals of increasing length
        for (size_t len = 2; len <= n + 1; ++len) {
            for (size_t left = 0; left <= n + 1 - len; ++left) {
                size_t right = left + len;
                // Try bursting each balloon k last in (left, right)
                for (size_t k = left + 1; k < right; ++k) {
                    int coins = dp[left][k] + 
                                balloons[left] * balloons[k] * balloons[right] + 
                                dp[k][right];
                    dp[left][right] = std::max(dp[left][right], coins);
                }
            }
        }

        // Result is max coins from bursting all balloons between 0 and n+1
        return dp[0][n + 1];
    }
};
```


***Testcases:***
```
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

```
Input: nums = [1,5]
Output: 10
```
