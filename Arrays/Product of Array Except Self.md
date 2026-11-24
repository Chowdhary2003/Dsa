***Problem:***
```
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    const int n = nums.size();
    std::vector<int> answer(n, 1); // Final output

    // Step 1: Prefix product pass
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    // Step 2: Suffix product pass (in-place multiply into answer)
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}
```


***Testcases:***
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```
