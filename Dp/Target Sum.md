***Problem:***
```
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
- For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.
```



***Complexity:***
```
       Time Complexity: O(n * S1)
       Space Complexity: O(S1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>
#include <limits>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // Check if the target is outside the possible range
        if (target > sum || target < -sum || (target + sum) % 2 != 0) {
            return 0;
        }

        // Calculate the subset sum S1
        int S1 = (target + sum) / 2;

        // Prevent overflow or large vector creation
        if (S1 > numeric_limits<int>::max() / 2) {
            return 0;  // Exit early if S1 is too large for a reasonable vector size
        }

        // DP array, where dp[i] stores the number of ways to get sum i
        vector<int> dp(S1 + 1, 0);
        dp[0] = 1;  // There's one way to get sum 0 (by choosing no elements)

        // Fill the DP table
        for (int num : nums) {
            for (int i = S1; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }

        return dp[S1];
    }
};
```


***Testcases:***
```
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

```
Input: nums = [1], target = 1
Output: 1
```
