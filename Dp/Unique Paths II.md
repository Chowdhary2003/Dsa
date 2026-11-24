***Problem:***
```
Medium
Topics
Companies
Hint
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 10^9.
```



***Complexity:***
```
       Time Complexity: O(m×n)
       Space Complexity: O(m×n)
```



***Code:***
```cpp
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // DP array to store the number of ways to reach each cell
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Start point (if no obstacle)
    if (grid[0][0] == 0) {
        dp[0][0] = 1;
    }

    // Fill the first row (can only come from the left)
    for (int j = 1; j < n; ++j) {
        if (grid[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the first column (can only come from above)
    for (int i = 1; i < m; ++i) {
        if (grid[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // Fill the rest of the grid
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}
```


***Testcases:***


![Screenshot 2025-05-20 190602](https://github.com/user-attachments/assets/c16c831d-6327-497e-9261-ffd5c45ca644)

