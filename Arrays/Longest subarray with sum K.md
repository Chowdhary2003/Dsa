***Problem:***
```
Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
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
#include <algorithm>

int longestSubarraySumK(const std::vector<int>& nums, int k) {
    // Map: prefix sum -> earliest index where this sum occurred
    std::unordered_map<long long, int> prefixIndices;
    prefixIndices[0] = -1; // Base case: sum 0 at index -1 (before start)
    
    long long prefixSum = 0;
    int maxLength = 0;
    
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        prefixSum += nums[i];
        
        // Check if there is a prefix sum that equals current sum minus k
        if (auto it = prefixIndices.find(prefixSum - k); it != prefixIndices.end()) {
            int length = i - it->second;
            maxLength = std::max(maxLength, length);
        }
        
        // Record earliest occurrence of this prefix sum to maximize sub-array length
        prefixIndices.try_emplace(prefixSum, i);
    }
    
    return maxLength;
}
```


***Testcases:***
```
Input: nums = [10, 5, 2, 7, 1, 9],  k=15
Output: 4
Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.
```

```
Input: nums = [-3, 2, 1], k=6
Output: 0
Explanation: There is no sub-array in the array that sums to 6. Therefore, the output is 0.
```
