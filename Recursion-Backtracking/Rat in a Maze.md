***Problem:***
```
Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).

Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).

The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.
```



***Complexity:***
```
       Time Complexity: O(4^(n^2))
       Space Complexity: O(n²) for visited matrix, O(n^2) Call stack depth
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0 || grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
            return {};

        vector<string> result;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path;

        visited[0][0] = true;
        dfs(0, 0, grid, visited, path, result);
        return result;
    }

private:
    // Directions: Down, Left, Right, Up
    const vector<pair<int, int>> directions = {{1,0}, {0,-1}, {0,1}, {-1,0}}; // D, L, R, U
    const string dirChars = "DLRU";

    void dfs(int r, int c, const vector<vector<int>>& grid,
             vector<vector<bool>>& visited, string& path, vector<string>& result) {
        int n = grid.size();

        // Base case: reached destination
        if (r == n - 1 && c == n - 1) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + directions[i].first;
            int nc = c + directions[i].second;

            if (isValid(nr, nc, grid, visited)) {
                visited[nr][nc] = true;
                path.push_back(dirChars[i]);
                dfs(nr, nc, grid, visited, path, result);
                path.pop_back();  // backtrack
                visited[nr][nc] = false;
            }
        }
    }

    bool isValid(int r, int c, const vector<vector<int>>& grid,
                 const vector<vector<bool>>& visited) {
        int n = grid.size();
        return r >= 0 && c >= 0 && r < n && c < n && grid[r][c] == 1 && !visited[r][c];
    }
};
```


### GFG
```cpp
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findPaths(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<string> result;
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) return result;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string path;
        dfs(mat, visited, 0, 0, path, result);
        return result;
    }

private:
    // Directions: D, L, R, U (to maintain lexicographical order)
    const vector<pair<int, char>> directions = {
        {1, 'D'}, {0, 'L'}, {0, 'R'}, {-1, 'U'}
    };
    const vector<int> dx = {1, 0, 0, -1};
    const vector<int> dy = {0, -1, 1, 0};
    const string dirChar = "DLRU";

    void dfs(const vector<vector<int>>& mat, vector<vector<bool>>& visited,
             int x, int y, string& path, vector<string>& result) {
        int n = mat.size();
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }

        visited[x][y] = true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            char move = dirChar[i];

            if (isValid(nx, ny, mat, visited)) {
                path.push_back(move);
                dfs(mat, visited, nx, ny, path, result);
                path.pop_back();  // backtrack
            }
        }

        visited[x][y] = false;  // backtrack
    }

    bool isValid(int x, int y, const vector<vector<int>>& mat, const vector<vector<bool>>& visited) {
        int n = mat.size();
        return x >= 0 && x < n && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y];
    }
};
```

***Testcases:***
```
Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]
Output : [ "DDRDRR" , "DRDDRR" ]
Explanation : The rat has two different path to reach (3, 3).
The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).
The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).
```

```
Input : n = 2 , grid = [ [1, 0] , [1, 0] ]
Output : -1
Explanation : There is no path that rat can choose to travel from (0,0) to (1,1).
```
