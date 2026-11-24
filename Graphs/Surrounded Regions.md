***Problem:***
```
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

- Connect: A cell is connected to adjacent cells horizontally or vertically.
- Region: To form a region connect every 'O' cell.
- Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
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

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Helper function for DFS
        auto dfs = [&](int i, int j) {
            // Stack for DFS, marking safe cells (connected to the boundary)
            stack<pair<int, int>> stk;
            stk.push({i, j});
            board[i][j] = 'S'; // Mark as safe (Temporary placeholder)
            
            while (!stk.empty()) {
                auto [x, y] = stk.top();
                stk.pop();
                
                // Check all 4 possible directions
                for (const auto& dir : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                        board[nx][ny] = 'S'; // Mark as safe
                        stk.push({nx, ny});
                    }
                }
            }
        };

        // Step 1: Mark all 'O's connected to the borders as safe ('S')
        // Check top and bottom borders
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][n-1] == 'O') dfs(i, n-1);
        }
        
        // Check left and right borders
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j);
            if (board[m-1][j] == 'O') dfs(m-1, j);
        }
        
        // Step 2: Capture all surrounded regions ('O' -> 'X')
        // and restore safe regions ('S' -> 'O')
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // Surrounded 'O' becomes 'X'
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';  // Safe 'O' returns to original 'O'
                }
            }
        }
    }
};
```


***Testcases:***

![Screenshot 2025-05-19 194935](https://github.com/user-attachments/assets/7709ae92-f176-44e2-8178-78c444c69cc1)
