# Shortest distance in binary maze

```cpp
#include <vector>

#include <queue>

#include <climits>

using namespace std;

class Solution {

public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid, int srcRow, int srcCol, int destRow, int destCol) {

        int n = grid.size();

        int m = grid[0].size();

        // Check if source or destination cell is blocked

        if (grid[srcRow][srcCol] == 0 || grid[destRow][destCol] == 0) {

            return -1;

        }

        // Array to store the shortest distance from source to each cell

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Queue for BFS traversal

        queue<pair<int, int>> q;

        // Starting from the source cell

        q.push({srcRow, srcCol});

        dist[srcRow][srcCol] = 0;

        // Possible movements in 8 directions (horizontal, vertical, diagonal)

        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};

        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        // Perform BFS traversal

        while (!q.empty()) {

            int currRow = q.front().first;

            int currCol = q.front().second;

            q.pop();

            // If the destination cell is reached, return the shortest distance

            if (currRow == destRow && currCol == destCol) {

                return dist[currRow][currCol];

            }

            // Explore the neighbors of the current cell

            for (int i = 0; i < 8; i++) {

                int newRow = currRow + dr[i];

                int newCol = currCol + dc[i];

                // Check if the neighbor is within the grid boundaries

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1) {

                    // Update the distance if a shorter path is found

                    if (dist[currRow][currCol] + 1 < dist[newRow][newCol]) {

                        dist[newRow][newCol] = dist[currRow][currCol] + 1;

                        q.push({newRow, newCol});

                    }

                }

            }

        }

        // If the destination cell is not reachable

        return -1;

    }

};

```
