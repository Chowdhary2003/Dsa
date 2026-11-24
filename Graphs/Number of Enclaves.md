***Problem:***
```
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
```



***Complexity:***
```
       Time Complexity: O(m * n)
       Space Complexity: O(m * n)
```



***Code:***
```cpp
#include <vector>
#include <stack>

class Solution {
public:
    int numEnclaves(std::vector<std::vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // DFS function to mark all connected land cells
        auto dfs = [&](int x, int y, auto&& dfs_ref) -> void {
            // If out of bounds or cell is not land, return
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return;
            grid[x][y] = 0; // Mark the cell as visited by setting it to 0
            
            // Move in all 4 directions
            dfs_ref(x + 1, y, dfs_ref);
            dfs_ref(x - 1, y, dfs_ref);
            dfs_ref(x, y + 1, dfs_ref);
            dfs_ref(x, y - 1, dfs_ref);
        };
        
        // Start DFS from all boundary cells
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) dfs(i, 0, dfs); // Left boundary
            if (grid[i][n - 1] == 1) dfs(i, n - 1, dfs); // Right boundary
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) dfs(0, j, dfs); // Top boundary
            if (grid[m - 1][j] == 1) dfs(m - 1, j, dfs); // Bottom boundary
        }
        
        // Count remaining land cells (those that can't escape)
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) result++;
            }
        }
        
        return result;
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 194957](https://github.com/user-attachments/assets/e99d4a2f-0b82-4282-ae94-9dfdf2538943)

