***Problem:***
```
You are given a binary matrix (it contains only 0s and 1s) with dimensions ‘N * M’. You need to find and return the sum of coverages of all zeros of the given matrix.

Coverage for a particular 0 is defined as the total number of ‘1s’ around it (i.e., immediate left, immediate right, immediate up, and immediate bottom positions).
```



***Complexity:***
```
       Time Complexity: O(N×M)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

int sumOfZeroCoverages(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    
    int totalCoverage = 0;

    // Directions: up, down, left, right
    const vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                int coverage = 0;
                for (const auto& [dx, dy] : directions) {
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        coverage += (matrix[ni][nj] == 1);
                    }
                }
                totalCoverage += coverage;
            }
        }
    }

    return totalCoverage;
}
```


***Testcases:***
```
Sample Input 1:
2 2 
1 0
0 1
Sample Output 1:
4
Explanation of Input 1:
In the given matrix, there are 2 zeros. 
For the 0 at the 1st row, 2nd column position, coverage is 2(there is 1 adjacent top one and 1 adjacent right one).
For the 0 at the 2nd row, 2nd column the coverage is 2(there is 1 adjacent top one and 1 adjacent right one).

Hence the net coverage is 2 + 2 = 4.
```

```
Sample Input 2:
2 3
0 0 0
0 0 0
Sample Output 2
0
```
