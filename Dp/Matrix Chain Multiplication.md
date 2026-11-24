***Problem:***
```
Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
```



***Complexity:***
```
       Time Complexity: O(n³)
       Space Complexity: O(n²)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <limits>

int matrixChainMultiplication(const std::vector<int>& arr) {
    const int n = arr.size();
    if (n <= 2) return 0; // only one matrix, no multiplication

    // dp[i][j] = min cost to multiply matrices from i to j
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // l = chain length
    for (int len = 2; len < n; ++len) {
        for (int i = 1; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {
                // Cost = cost of multiplying left + right + cost of multiplying results
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                dp[i][j] = std::min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n - 1]; // min cost to multiply matrices 1 to n-1
}
```


***Testcases:***
```
Input: arr[] = [2, 1, 3, 4]
Output: 20
Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let this 3 input matrices be M1, M2, and M3. There are two ways to multiply: ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix. 
((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30 
(M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20. 
The minimum of these two is 20.
```

```
Input: arr[] = [1, 2, 3, 4, 3]
Output: 30
Explanation: There are 4 matrices of dimensions 1 × 2, 2 × 3, 3 × 4, 4 × 3. Let this 4 input matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1 x M2) x M3) x M4). The minimum number is (1 x 2 x 3) + (1 x 3 x 4) + (1 x 4 x 3) = 30.
```

```
Input: arr[] = [3, 4]
Output: 0
Explanation: As there is only one matrix so, there is no cost of multiplication.
```
