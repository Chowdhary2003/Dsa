***Problem:***
```
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target
```



***Complexity:***
```
       Time Complexity: O(n³)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        const int n = nums.size();
        if (n < 4) return result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate 'i' values
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate 'j' values
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to avoid overflow
                    long long sum = static_cast<long long>(nums[i])
                                  + nums[j]
                                  + nums[left]
                                  + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        ++left;
                        --right;

                        // Skip duplicates after moving pointers
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    }
                    else if (sum < target) {
                        ++left;  // Need a larger sum
                    }
                    else {
                        --right; // Need a smaller sum
                    }
                }
            }
        }

        return result;
    }
};
```


***Testcases:***
```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

```
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
```
