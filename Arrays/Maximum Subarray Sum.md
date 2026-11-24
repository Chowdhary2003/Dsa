***Problem:***
```
Given an integer array nums, find the subarray with the largest sum, and return its sum.

A subarray is a contiguous segment of an array. In other words, a subarray can be formed by removing 0 or more integers from the beginning and 0 or more integers from the end of an array.

Find the sum of the subarray (including empty subarray) having maximum sum among all subarrays.

The sum of an empty subarray is 0.
```

or

```
Given an integer array nums, find the subarray with the largest sum, and return its sum.
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
#include <limits>    // for std::numeric_limits

int maxSubArray(const std::vector<int>& nums) {
    // Initialize to the smallest possible integer
    int max_sum = std::numeric_limits<int>::min();
    int current_sum = 0;

    for (int num : nums) {
        current_sum = std::max(num, current_sum + num); // Either extend or start fresh
        max_sum = std::max(max_sum, current_sum);       // Track global max
    }

    return max_sum;
}
```


***Testcases:***
```
Example :
Input: 'arr' = [1, 2, 7, -4, 3, 2, -10, 9, 1]
Output: 11
Explanation: The subarray yielding the maximum sum is [1, 2, 7, -4, 3, 2].
```

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```


```
Sample Input 3 :
-3 -5 -6
Sample Output 3 :
0
```


```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```
