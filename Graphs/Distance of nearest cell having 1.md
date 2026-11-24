# Distance of nearest cell having 1

```cpp
vector<vector<int>> nearest(vector<vector<int>>& grid) {

    // Retrieving the dimensions of the grid

    int n = grid.size();  // Number of rows

    int m = grid[0].size();  // Number of columns

    // Creating a 2D vector to store the distances

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

    // dp[i][j] represents the distance of cell (i, j) from the nearest cell with a value of 1

    queue<pair<int, int>> q;  // Queue for BFS traversal

    // Marking the distance of cells with 1 as 0 and enqueueing them

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 1) {

                dp[i][j] = 0;  // Distance to the same cell is 0

                q.push({i, j});  // Enqueue the cell (i, j) with a value of 1

            }

        }

    }

    // Vectors for exploring adjacent cells in all directions

    vector<int> dx = {1, -1, 0, 0};  // Change in row coordinate

    vector<int> dy = {0, 0, 1, -1};  // Change in column coordinate

    // BFS traversal

    while (!q.empty()) {

        int x = q.front().first;

        int y = q.front().second;

        q.pop();

        // Checking all four adjacent cells

        for (int i = 0; i < 4; i++) {

            int n_x = x + dx[i];  // New row coordinate

            int n_y = y + dy[i];  // New column coordinate

            // Validating the neighboring cell and updating its distance

            if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && dp[n_x][n_y] == INT_MAX) {

                dp[n_x][n_y] = dp[x][y] + 1;  // Update the distance of the neighboring cell

                q.push({n_x, n_y});  // Enqueue the neighboring cell

            }

        }

    }

    return dp;  // Return the 2D vector containing the distances

}

```
