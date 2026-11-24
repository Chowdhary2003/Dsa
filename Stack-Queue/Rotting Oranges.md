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
       Time Complexity: O(m * n)
       Space Complexity: O(m * n)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> rotten; // stores rotten oranges positions
        int freshCount = 0;

        // Initialize queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)
                    rotten.emplace(i, j);
                else if (grid[i][j] == 1)
                    ++freshCount;
            }
        }

        if (freshCount == 0) return 0;  // No fresh oranges to rot

        constexpr int dx[] = {1, -1, 0, 0};
        constexpr int dy[] = {0, 0, 1, -1};

        int minutes = 0;
        while (!rotten.empty() && freshCount > 0) {
            int size = rotten.size();

            for (int i = 0; i < size; ++i) {
                auto [x, y] = rotten.front(); rotten.pop();

                for (int d = 0; d < 4; ++d) {
                    int nx = x + dx[d], ny = y + dy[d];
                    // Check bounds and if fresh orange
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;  // Rot it
                        --freshCount;
                        rotten.emplace(nx, ny);
                    }
                }
            }
           if (!rotten.empty()) ++minutes;  // increment only if fresh oranges were infected
        }
        return freshCount == 0 ? minutes : -1;
    }
};
```


***Testcases:***

<img width="1306" height="275" alt="oranges" src="https://github.com/user-attachments/assets/25c38989-a106-486d-b563-c688a151d11d" />


```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

```
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```

```
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
```
