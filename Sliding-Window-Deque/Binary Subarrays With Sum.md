***Problem:***
```
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.
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

class Solution {
public:
    int numSubarraysWithSum(const vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // Base case: sum 0 has occurred once.

        int currentSum = 0;
        int result = 0;

        for (int num : nums) {
            currentSum += num;

            // Count how many times we've seen (currentSum - goal)
            if (prefixCount.count(currentSum - goal)) {
                result += prefixCount[currentSum - goal];
            }

            // Record this prefix sum
            ++prefixCount[currentSum];
        }

        return result;
    }
};
```


***Testcases:***
```
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
```

```
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
```
