***Problem:***
```
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
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

int longestOnes(const vector<int>& nums, int k) {
    int left = 0, maxLen = 0, zeroCount = 0;

    for (int right = 0; right < nums.size(); ++right) {
        if (nums[right] == 0)
            ++zeroCount;

        // Shrink the window if too many 0s
        while (zeroCount > k) {
            if (nums[left] == 0)
                --zeroCount;
            ++left;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
```


***Testcases:***
```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

```
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```
