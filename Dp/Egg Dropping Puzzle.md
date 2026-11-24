***Problem:***
```
You are given n identical eggs and you have access to a k-floored building from 1 to k.

There exists a floor f where 0 <= f <= k such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
There are few rules given below. 

- An egg that survives a fall can be used again.
- A broken egg must be discarded.
- The effect of a fall is the same for all eggs.
- If the egg doesn't break at a certain floor, it will not break at any floor below.
- If the egg breaks on a certain floor, it will break on any floor above.

Return the minimum number of moves you need to determine the value of f with certainty.
```



***Complexity:***
```
       Time Complexity: O(n * m)
       Space Complexity: O(n * m)
```



***Code:***
```cpp
#include <iostream>
#include <vector>

int superEggDrop(int n, int k) {
    // dp[m][e]: max floors with m moves and e eggs
    std::vector<std::vector<int>> dp(k+1, std::vector<int>(n+1, 0));
    
    int m = 0; // moves
    
    // Increase moves until we can cover k floors with n eggs
    while (dp[m][n] < k) {
        ++m;
        for (int e = 1; e <= n; ++e) {
            // Formula: floors testable = 1 + floors below + floors above
            dp[m][e] = 1 + dp[m-1][e-1] + dp[m-1][e];
        }
    }
    
    return m;
}
```


***Testcases:***
```
Input: n = 2, k = 36
Output: 8
Explanation: In all the situations, 8 maximum moves are required to find the maximum floor. Following is the strategy to do so:
Drop from floor 8 → If breaks, check 1-7 sequentially.
Drop from floor 15 → If breaks, check 9-14.
Drop from floor 21  → If breaks, check 16-20.
Drop from floor 26 → If breaks, check 22-25.
Drop from floor 30 → If breaks, check 27-29.
Drop from floor 33 → If breaks, check 31-32.
Drop from floor 35 → If breaks, check 34.
Drop from floor 36 → Final check.
```

```
Input: n = 1, k = 36
Output: 36
Explanation: Drop the egg from the first-floor window; if it survives, drop it from the second-floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings.
```
