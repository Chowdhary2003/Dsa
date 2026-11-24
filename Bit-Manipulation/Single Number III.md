***Problem:***
```
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(const std::vector<int>& nums) {
    // Use unsigned int for XOR accumulator to avoid signed overflow/UB
    unsigned int xor_all = 0u;
    for (int num : nums) {
        xor_all ^= static_cast<unsigned int>(num);
    }

    // Isolate rightmost set bit in xor_all safely in unsigned domain
    unsigned int diff_bit = xor_all & (~xor_all + 1u);

    int x = 0, y = 0;
    for (int num : nums) {
        if ((static_cast<unsigned int>(num) & diff_bit) != 0) {
            x ^= num;
        } else {
            y ^= num;
        }
    }

    return {x, y};
    }
};
```


***Testcases:***
```
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
```

```
Input: nums = [-1,0]
Output: [-1,0]
```

```
Input: nums = [0,1]
Output: [1,0]
```
