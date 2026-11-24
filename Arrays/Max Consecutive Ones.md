***Problem:***
```
Given a binary array nums, return the maximum number of consecutive 1's in the array.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // for std::max

int findMaxConsecutiveOnes(const std::vector<int>& nums) {
    int maxLen = 0;
    int current = 0;

    for (int num : nums) {
        if (num == 1) {
            ++current; // increment current streak
            maxLen = std::max(maxLen, current); // update max streak
        } else {
            current = 0; // reset on zero
        }
    }

    return maxLen;
}
```


***Testcases:***
```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
```

```
Input: nums = [1,0,1,1,0,1]
Output: 2
```
