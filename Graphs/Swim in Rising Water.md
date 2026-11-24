***Problem:***
```
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
```



***Complexity:***
```
       Time Complexity: O(n² log n)
       Space Complexity: O(n²)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Directions for 4 neighbors (up, down, left, right)
        const vector<pair<int,int>> directions {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        // Priority queue for BFS (min-heap)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start with the top-left corner (0, 0) with elevation grid[0][0]
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        while (!pq.empty()) {
            // Get the cell with the smallest water level
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            // If we reach the bottom-right corner, return the time
            if (x == n - 1 && y == n - 1) {
                return time;
            }
            
            // Explore the 4 possible neighbors
            for (const auto& d : directions) {
                int nx = x + d.first;
                int ny = y + d.second;
                
                // Check if the neighbor is within bounds and not visited
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // Push the neighbor with the maximum of current time and the neighbor's elevation
                    pq.push({max(time, grid[nx][ny]), {nx, ny}});
                }
            }
        }
        
        return -1; // This should never happen
    }
};
```


***Testcases:***

![Screenshot 2025-05-20 155602](https://github.com/user-attachments/assets/d764dab2-f82c-4f73-84a8-9f779d45c746)


