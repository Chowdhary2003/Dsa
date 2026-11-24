***Problem:***
```
Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.
```



***Complexity:***
```
       Time Complexity: O(n * target)
       Space Complexity: O(target)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <numeric>

bool isSubsetSum(const std::vector<int>& arr, int target) {
    if (target < 0) return false;  // Early rejection for negative target

    int n = arr.size();

    // Optimization: if target is negative or larger than sum, impossible
    int totalSum = std::accumulate(arr.begin(), arr.end(), 0);
    if (target > totalSum || target < 0) return false;  // Early pruning

    // dp[i] = whether a subset can form sum i
    std::vector<bool> dp(target + 1, false);
    dp[0] = true; // Empty subset always forms sum 0

    for (int num : arr) {
        if (num > target) continue; // small optimization to skip large numbers
        // Traverse backward to prevent reusing the same element
        for (int t = target; t >= num; --t) {
            dp[t] = dp[t] || dp[t - num];
        }
    }

    return dp[target];
}
```


***Testcases:***
```
Input: arr = [1, 2, 7, 3], target = 6
Output: True
Explanation: There is a subset (1, 2, 3) with sum 6.
```

```
Input: arr = [2, 3, 5], target = 6
Output: False
Explanation: There is no subset with sum 6.
```
