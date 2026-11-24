***Problem:***
```
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

int singleNumber(const std::vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int num : nums) {
        // Update `ones` with bits that have appeared once
        ones = (ones ^ num) & ~twos;

        // Update `twos` with bits that have appeared twice
        twos = (twos ^ num) & ~ones;
    }
    return ones; // Only the unique number's bits remain in `ones`
}
```


***Testcases:***
```
Input: nums = [2,2,3,2]
Output: 3
```

```
Input: nums = [0,1,0,1,0,1,99]
Output: 99
```
