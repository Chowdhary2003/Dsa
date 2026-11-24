***Problem:***
```
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.
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
#include <utility> // for std::pair
#include <limits>  // for std::numeric_limits

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return {};

        const int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));

        queue<pair<int, int>> q;

        // Initialize queue with all zero cells and set distance 0 for them
        for (size_t i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        // Directions for neighbors: up, down, left, right
        const vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // Standard BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                // Check boundaries and if we can improve distance
                if (nr >= 0 && nr < static_cast<int>(m) && nc >= 0 && nc < static_cast<int>(n)) {
                    // If this neighbor can be relaxed (shorter distance found)
                    if (dist[nr][nc] > dist[r][c] + 1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.emplace(nr, nc);
                    }
                }
            }
        }

        return dist;
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/258df736-5169-4ffc-b1e7-eae5333ab924" width="500" />



<img src="https://github.com/user-attachments/assets/008a6655-4154-493c-b3b5-619186110350" width="500" />


