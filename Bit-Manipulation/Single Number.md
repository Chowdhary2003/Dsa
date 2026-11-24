
***Problem:***
```
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
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

int singleNumber(const std::vector<int>& nums) {
    int result = 0; // Initialize result to 0
    for (int num : nums) {
        result ^= num; // XOR each number with result
    }
    return result; // The result will be the unique element
}
```


***Testcases:***
```
Input: nums = [2,2,1]
Output: 1
```


```
Input: nums = [4,1,2,1,2]
Output: 4
```

```
Input: nums = [1]
Output: 1
```
