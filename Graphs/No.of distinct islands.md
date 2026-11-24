# No.of distinct islands

```cpp
class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        // Mark the current cell as visited
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col}); // Push the current cell into the queue
        int n = grid.size();
        int m = grid[0].size();

        // While the queue is not empty, perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse in all four directions
            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    // Check if the neighbor cell is valid and unvisited land
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol}); // Push the neighbor cell into the queue
                    }
                }
            }
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Create a visited array and initialize it to 0
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0; // Counter for the number of islands

        // Traverse the grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If the cell is unvisited land, increment the counter and perform BFS
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid); // Perform BFS from the current land cell
                }
            }
        }

        return cnt; // Return the number of islands
    }
};
```
