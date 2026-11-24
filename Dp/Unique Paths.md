***Problem:***
```
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
```



***Complexity:***
```
       Time Complexity: O(m * n)
       Space Complexity: O(n)
```



***Code:***
```cpp
// ✅ DP approach: O(m*n) time and O(n) space
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use a 1D DP array to optimize space
        std::vector<int> dp(n, 1);  // Base case: only 1 way to reach cells in first row

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; // dp[j] = dp[j] (from above) + dp[j-1] (from left)
            }
        }
        return dp[n - 1];
    }
};
```


```cpp
// ✅ Combinatorics version: O(min(m, n)) time and O(1) space
#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    // Compute C(m+n-2, m-1) iteratively to avoid overflow
    long res = 1;
    int total = m + n - 2;
    int k = min(m - 1, n - 1);  // C(total, k)
    for (int i = 1; i <= k; ++i) {
        res = res * (total - i + 1) / i;
    }
    return static_cast<int>(res);
}
```


***Testcases:***

<img width="876" height="1000" alt="Screenshot 2025-07-13 102147" src="https://github.com/user-attachments/assets/d1801cc8-eaf1-4053-9719-df59edbddade" />

