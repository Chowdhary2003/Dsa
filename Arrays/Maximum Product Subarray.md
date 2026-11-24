***Problem:***
```
Given an integer array nums, find a subarray that has the largest product, and return the product.

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
#include <algorithm> // for std::max, std::min

int maxProduct(const std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        int current = nums[i];

        // Swapping if current is negative flips roles
        if (current < 0) {
            std::swap(max_so_far, min_so_far);
        }

        max_so_far = std::max(current, max_so_far * current);
        min_so_far = std::min(current, min_so_far * current);

        result = std::max(result, max_so_far);
    }

    return result;
}
```


***Testcases:***
```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```

```
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```
