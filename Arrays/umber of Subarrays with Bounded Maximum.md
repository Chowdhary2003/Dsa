***Problem:***
```
Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].

The test cases are generated so that the answer will fit in a 32-bit integer.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // Counts number of subarrays where all elements <= bound
    int countSubarrays(const vector<int>& nums, int bound) {
        int count = 0, length = 0;
        for (int num : nums) {
            if (num <= bound) {
                length++;        // Extend current valid subarray
                count += length; // All subarrays ending here
            } else {
                length = 0;      // Reset because num > bound breaks validity
            }
        }
        return count;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // Count subarrays with max <= right
        int countRight = countSubarrays(nums, right);
        // Count subarrays with max < left (i.e. max <= left-1)
        int countLeft = countSubarrays(nums, left - 1);

        return countRight - countLeft;
    }
};
```


***Testcases:***
```
Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
```

```
Input: nums = [2,9,2,5,6], left = 2, right = 8
Output: 7
```
