***Problem:***
```
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:
- Robot #1 is located at the top-left corner (0, 0), and
- Robot #2 is located at the top-right corner (0, cols - 1).

Return the maximum number of cherries collection using both robots by following the rules below:

- From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
- When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
- When both robots stay in the same cell, only one takes the cherries.
- Both robots cannot move outside of the grid at any moment.
- Both robots should reach the bottom row in grid.
```



***Complexity:***
```
       Time Complexity: O(rows * cols^2)
       Space Complexity: O(rows * cols^2)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();

        // 3D DP cache: dp[row][col1][col2]
        // Stores max cherries collected starting from this state
        vector<vector<vector<int>>> dp(rows,
            vector<vector<int>>(cols, vector<int>(cols, -1)));

        return dfs(grid, 0, 0, cols - 1, dp);
    }

private:
    int dfs(const vector<vector<int>>& grid, int row, int col1, int col2,
            vector<vector<vector<int>>>& dp) {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();

        // Boundary check
        if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols)
            return INT_MIN; // invalid path

        // Base case: last row
        if (row == rows - 1) {
            if (col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }

        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

        // Current cherries collected
        int cherries = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

        int max_cherries = INT_MIN;

        // Try all moves for both robots (3x3 = 9)
        for (int new_col1 = col1 - 1; new_col1 <= col1 + 1; ++new_col1) {
            for (int new_col2 = col2 - 1; new_col2 <= col2 + 1; ++new_col2) {
                int temp = dfs(grid, row + 1, new_col1, new_col2, dp);
                max_cherries = max(max_cherries, temp);
            }
        }

        dp[row][col1][col2] = cherries + max_cherries;
        return dp[row][col1][col2];
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/18db0830-b8eb-47c1-bdf8-6f1beed13738" width="500" alt="Screenshot 1" />


<img src="https://github.com/user-attachments/assets/35a23a4a-8d51-46d3-b88d-1d9b79a105e1" width="500" alt="Screenshot 2" />
