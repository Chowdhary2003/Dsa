***Problem:***
```
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
```



***Complexity:***
```
       Time Complexity: O(m * n)
       Space Complexity: O(min(m, n)) in DFS stack in worst case
```



***Code:***
```cpp
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = int(grid.size());
        int n = int(grid[0].size());
        int islandCount = 0;
        
        // Directions: up, down, left, right
        const vector<pair<int,int>> directions{{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++islandCount;
                    // Use DFS to mark all connected land as visited
                    markIsland(grid, i, j, m, n, directions);
                }
            }
        }
        return islandCount;
    }

private:
    void markIsland(vector<vector<char>>& grid, int x, int y, int m, int n,
                    const vector<pair<int,int>>& directions) {
        stack<pair<int,int>> stk;
        stk.emplace(x, y);
        grid[x][y] = '0'; // mark visited by sinking the island
        
        while (!stk.empty()) {
            auto [cx, cy] = stk.top();
            stk.pop();
            
            for (const auto& [dx, dy] : directions) {
                int nx = cx + dx;
                int ny = cy + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                    grid[nx][ny] = '0';  // mark visited
                    stk.emplace(nx, ny);
                }
            }
        }
    }
};
```


***Testcases:***
```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```
