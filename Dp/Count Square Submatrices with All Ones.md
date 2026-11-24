***Problem:***
```
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
```



***Complexity:***
```
       Time Complexity: O(m * n)
       Space Complexity: O(m * n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // For min function
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0)); // DP table
    
    int totalCount = 0; // To store the total count of squares
    
    // Iterate through the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // Edge case for the first row or column
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                totalCount += dp[i][j]; // Add the number of squares ending at (i, j)
            }
        }
    }
    
    return totalCount;
}
```


***Testcases:***
```
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
```

```
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
```
