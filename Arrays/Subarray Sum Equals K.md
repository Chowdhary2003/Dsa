***Problem:***
```
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n) in worst case
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>

int subarraySum(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prefix_count;
    prefix_count[0] = 1; // To handle the case where prefix_sum == k

    int count = 0;
    int prefix_sum = 0;

    for (int num : nums) {
        prefix_sum += num;

        // Check if there is a prefix that satisfies the condition
        if (auto it = prefix_count.find(prefix_sum - k); it != prefix_count.end()) {
            count += it->second;
        }

        // Record the current prefix_sum for future subarrays
        ++prefix_count[prefix_sum];
    }

    return count;
}
```


***Testcases:***
```
Input: nums = [1,1,1], k = 2
Output: 2
```

```
Input: nums = [1,2,3], k = 3
Output: 2
```
