***Problem:***
```
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <stdexcept> // for std::invalid_argument

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen; // maps num → index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // Check if we've already seen the complement
        if (auto it = seen.find(complement); it != seen.end()) {
            return {it->second, i}; // Return stored index and current index
        }

        // Store current number with its index
        seen[nums[i]] = i;
    }

    // Should never reach here if there's exactly one solution
    throw std::invalid_argument("No valid solution found.");
}
```


***Testcases:***
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

```
Input: nums = [3,3], target = 6
Output: [0,1]
```
