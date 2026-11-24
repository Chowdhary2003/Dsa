***Problem:***
```
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return std::max(nums[0], nums[1]);

        // Helper function to solve the linear version of the problem
        auto rob_linear = [](const std::vector<int>& houses) -> int {
            int prev1 = 0, prev2 = 0;
            for (int val : houses) {
                int take = val + prev2;   // Rob current, skip previous
                int skip = prev1;         // Skip current
                int curr = std::max(take, skip);
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        };

        int max_exclude_last = rob_linear(vector<int>(nums.begin(), nums.end() - 1));
        int max_exclude_first = rob_linear(vector<int>(nums.begin() + 1, nums.end()));
        return max(max_exclude_last, max_exclude_first);
    }
};
```


***Testcases:***
```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

```
Input: nums = [1,2,3]
Output: 3
```
