***Problem:***
```
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1) extra (in-place); O(n)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    // Compute prefix sums in-place for O(1) extra space
    for (size_t i = 1; i < nums.size(); ++i) {
        nums[i] += nums[i - 1];
    }
    return nums;
}
```


***Testcases:***
```
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

```
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```


```
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
```
