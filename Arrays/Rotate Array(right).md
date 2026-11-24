***Problem:***
```
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // for std::reverse

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1 || k % n == 0) return;

    k %= n; // normalize k if greater than n

    // Step 1: reverse the whole array
    std::reverse(nums.begin(), nums.end());

    // Step 2: reverse the first k elements
    std::reverse(nums.begin(), nums.begin() + k);

    // Step 3: reverse the remaining elements
    std::reverse(nums.begin() + k, nums.end());
}
```


***Testcases:***
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```
