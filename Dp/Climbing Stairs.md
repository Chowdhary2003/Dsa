***Problem:***
```
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <vector>

class Solution {
public:
    // Computes the number of distinct ways to climb n steps
    int climbStairs(int n) {
        if (n <= 2) return n; // Base cases: 1->1 way, 2->2 ways

        int prev2 = 1; // ways to climb to step 1
        int prev1 = 2; // ways to climb to step 2
        int current = 0;

        // Compute dp iteratively from step 3 to n
        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;  // dp[i] = dp[i-1] + dp[i-2]
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};
```


***Testcases:***
```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```
