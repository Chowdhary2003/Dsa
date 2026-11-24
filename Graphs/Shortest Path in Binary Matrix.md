***Problem:***
```
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
- All the visited cells of the path are 0.
- All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n^2)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;
        
        // Directions: 8 possible moves (up, down, left, right, and diagonals)
        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {1, 1},
            {-1, 0}, {0, -1}, {-1, -1},
            {1, -1}, {-1, 1}
        };

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        grid[0][0] = 1; // use grid to track visited and path length

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            int dist = grid[x][y];
            if (x == n - 1 && y == n - 1)
                return dist;

            for (const auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    q.emplace(nx, ny);
                    grid[nx][ny] = dist + 1; // mark as visited with distance
                }
            }
        }

        return -1;
    }
};
```


***Testcases:***


![Screenshot 2025-05-20 145837](https://github.com/user-attachments/assets/8f2ba460-a132-46f2-b18d-ea652c9ca32a)

