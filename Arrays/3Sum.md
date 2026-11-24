***Problem:***
```
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
```



***Complexity:***
```
       Time Complexity: O(n²)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    const int n = static_cast<int>(nums.size());
    if (n < 3) return result;  // Early return on small input

    std::sort(nums.begin(), nums.end());  // Sort to apply two-pointer approach

    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicate fixed elements to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            const int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates before moving pointers
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;

                ++left;
                --right;
            }
            else if (sum < 0) {
                ++left;  // Need a larger sum
            }
            else {
                --right; // Need a smaller sum
            }
        }
    }
    return result;
}
```


***Testcases:***
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```


```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
```


```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
```
