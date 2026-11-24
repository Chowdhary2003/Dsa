***Problem:***
```
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
```



***Complexity:***
```
       Time Complexity: O(M * N * log(M*N))
       Space Complexity: O(M * N)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> effort(rows, vector<int>(cols, numeric_limits<int>::max()));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        effort[0][0] = 0;
        minHeap.emplace(0, 0, 0); // {effort, row, col}

        while (!minHeap.empty()) {
            auto [curEffort, row, col] = minHeap.top();
            minHeap.pop();

            if (row == rows - 1 && col == cols - 1)
                return curEffort;

            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int nextEffort = max(curEffort, abs(heights[nr][nc] - heights[row][col]));
                    if (nextEffort < effort[nr][nc]) {
                        effort[nr][nc] = nextEffort;
                        minHeap.emplace(nextEffort, nr, nc);
                    }
                }
            }
        }

        return 0; // Should never reach here
    }
};
```


***Testcases:***

![Screenshot 2025-05-20 150105](https://github.com/user-attachments/assets/16951774-75a3-4d4f-910e-c3527f98a826)


![Screenshot 2025-05-20 150115](https://github.com/user-attachments/assets/37c92052-28c6-40ee-8871-73409197544f)
