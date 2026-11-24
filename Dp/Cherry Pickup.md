***Problem:***
```
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

- 0 means the cell is empty, so you can pass through,
- 1 means the cell contains a cherry that you can pick up and pass through, or
- -1 means the cell contains a thorn that blocks your way.

Return the maximum number of cherries you can collect by following the rules below:

- Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
- After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
- When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
- If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
```



***Complexity:***
```
       Time Complexity: O(n³)
       Space Complexity: O(n³)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        // dp[r1][c1][r2] stores max cherries when person A at (r1, c1), person B at (r2, c2)
        // where c2 = r1 + c1 - r2 (total steps t = r1 + c1 = r2 + c2)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, numeric_limits<int>::min())));
        
        dp[0][0][0] = grid[0][0];

        for (int t = 1; t <= 2 * (n - 1); ++t) {
            vector<vector<vector<int>>> dpNew(n, vector<vector<int>>(n, vector<int>(n, numeric_limits<int>::min())));
            for (int r1 = max(0, t - (n - 1)); r1 <= min(n - 1, t); ++r1) {
                int c1 = t - r1;
                if (c1 >= n) continue;
                for (int r2 = max(0, t - (n - 1)); r2 <= min(n - 1, t); ++r2) {
                    int c2 = t - r2;
                    if (c2 >= n) continue;
                    // Blocked cell check
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;

                    int cherries = grid[r1][c1];
                    if (r1 != r2 || c1 != c2) cherries += grid[r2][c2];

                    // Check 4 possible previous states
                    int bestPrev = numeric_limits<int>::min();
                    for (int pr1 = r1 - 1; pr1 <= r1; ++pr1) {
                        for (int pr2 = r2 - 1; pr2 <= r2; ++pr2) {
                            int pc1 = t - 1 - pr1;
                            int pc2 = t - 1 - pr2;

                            if (pr1 >= 0 && pr2 >= 0 && pc1 >= 0 && pc2 >= 0 &&
                                pr1 < n && pr2 < n && pc1 < n && pc2 < n) {
                                if (dp[pr1][pc1][pr2] != numeric_limits<int>::min()) {
                                    bestPrev = max(bestPrev, dp[pr1][pc1][pr2]);
                                }
                            }
                        }
                    }

                    if (bestPrev == numeric_limits<int>::min()) continue;
                    dpNew[r1][c1][r2] = bestPrev + cherries;
                }
            }
            dp = move(dpNew);
        }

        return max(0, dp[n - 1][n - 1][n - 1]);
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/a39ba1b8-ce9a-4ee3-9b91-a75ed5ee68f5" width="500" alt="Screenshot" />
