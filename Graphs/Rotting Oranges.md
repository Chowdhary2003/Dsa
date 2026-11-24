***Problem:***
```
You are given an m x n grid where each cell can have one of three values:
- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
```



***Complexity:***
```
       Time Complexity: O(m*n)
       Space Complexity: O(m*n)
```



***Code:***
```cpp
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q; // positions of rotten oranges
        int freshCount = 0;

        // Directions for 4-adjacency: up, down, left, right
        const vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        // Initialize queue with all rotten oranges and count fresh ones
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                } else if (grid[i][j] == 1) {
                    ++freshCount;
                }
            }
        }

        if (freshCount == 0) return 0; // no fresh oranges to rot

        int minutes = 0;

        // BFS level by level
        while (!q.empty()) {
            int levelSize = q.size();
            bool infectedThisRound = false;

            for (int i = 0; i < levelSize; ++i) {
                auto [x, y] = q.front(); q.pop();

                for (auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    // Check boundaries and if neighbor is fresh
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;       // rot this orange
                        --freshCount;
                        q.emplace(nx, ny);
                        infectedThisRound = true;
                    }
                }
            }

            if (infectedThisRound) {
                ++minutes;  // increment only if some oranges got infected this round
            }
        }

        return (freshCount == 0) ? minutes : -1;
    }
};
```


***Testcases:***

<img width="1746" height="974" alt="Screenshot 2025-07-11 084638" src="https://github.com/user-attachments/assets/bdaf0f95-4c1a-446d-b499-84e854c08676" />
