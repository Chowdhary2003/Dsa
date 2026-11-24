***Problem:***
```
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
```



***Complexity:***
```
       Time Complexity: O(min(m, n))
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>

int uniquePaths(int m, int n) {
    // Using combinatorics: C(m+n-2, m-1)
    long long res = 1;
    int N = m + n - 2;
    int k = std::min(m - 1, n - 1); // C(N, k) = C(N, N-k)

    for (int i = 1; i <= k; ++i) {
        res = res * (N - i + 1) / i; // integer division is safe here
    }

    return static_cast<int>(res); // guaranteed to fit in int
}
```


***Testcases:***


<img src="https://github.com/user-attachments/assets/6818e510-805c-4302-8b4b-e6cc59f0a201" width="500" />


```
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```
