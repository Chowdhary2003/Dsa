***Problem:***
```
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
```



***Complexity:***
```
       Time Complexity: O(m*n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::min;

class Solution {
public:
    int minPathSum(const vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = (int)grid.size();
        int n = (int)grid[0].size();

        // Using a single vector for DP to optimize space
        vector<int> dp(n, 0);

        // Initialize dp[0] for the first row
        dp[0] = grid[0][0];

        // Initialize first row (only right moves possible)
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        // Fill dp for the rest of the grid row by row
        for (int i = 1; i < m; ++i) {
            // Update the first column of the current row (only down moves)
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                // Take min of coming from top (dp[j]) or left (dp[j-1])
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/37507c8b-967f-418d-8ca6-f43eb5df3382" width="500" alt="Screenshot" />
