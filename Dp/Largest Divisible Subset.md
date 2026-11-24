***Problem:***
```
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
- answer[i] % answer[j] == 0, or
- answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.empty()) return {};
    
    // Step 1: Sort the numbers to simplify checking divisibility
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    
    // Step 2: dp[i] represents the size of the largest divisible subset ending at nums[i]
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);  // To reconstruct the path of the largest subset
    
    int maxSize = 1;
    int maxIndex = 0;
    
    // Step 3: Dynamic Programming - Find the largest subset
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxSize) {
            maxSize = dp[i];
            maxIndex = i;
        }
    }
    
    // Step 4: Reconstruct the subset
    vector<int> result;
    while (maxIndex != -1) {
        result.push_back(nums[maxIndex]);
        maxIndex = parent[maxIndex];
    }
    
    // Step 5: Reverse the result to get the subset in increasing order
    reverse(result.begin(), result.end());
    return result;
}
```


***Testcases:***
```
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
```

```
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
```
