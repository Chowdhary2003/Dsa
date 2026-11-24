***Problem:***
```
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n^2)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> island(n, vector<int>(n, 0));
        unordered_map<int, int> islandSize;
        int islandId = 1;

        // Directions for 4-directional movement
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Helper function for DFS
        function<int(int, int, int)> dfs = [&](int x, int y, int id) {
            island[x][y] = id;
            int size = 1;
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && island[nx][ny] == 0) {
                    size += dfs(nx, ny, id);
                }
            }
            return size;
        };

        // Step 1: Assign island ids and calculate island sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && island[i][j] == 0) {
                    int size = dfs(i, j, islandId);
                    islandSize[islandId] = size;
                    islandId++;
                }
            }
        }

        // Step 2: Find the largest island without flipping
        int maxIsland = 0;
        for (auto& [id, size] : islandSize) {
            maxIsland = max(maxIsland, size);
        }

        // Step 3: Consider flipping a 0 to 1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> adjacentIslands;
                    int newSize = 1; // Start with the flipped cell itself

                    // Check the four neighbors
                    for (auto& dir : directions) {
                        int nx = i + dir.first, ny = j + dir.second;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && island[nx][ny] > 0) {
                            adjacentIslands.insert(island[nx][ny]);
                        }
                    }

                    // Add the sizes of the adjacent islands
                    for (int adjId : adjacentIslands) {
                        newSize += islandSize[adjId];
                    }

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};
```


***Testcases:***
```
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```

```
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
```


```
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
```
