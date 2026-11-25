# Find the maximum element in a Matrix

## Problem
```
Given an NxM matrix. The task is to find the maximum element in this matrix.
```



## Complexity
```
       Time Complexity: O(N * M)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <vector>
#include <iostream>
#include <limits> // for std::numeric_limits

// Function to find the maximum element in the matrix
int findMaxElement(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        throw std::invalid_argument("Matrix is empty");
    }
    
    // Initialize maxVal to the smallest possible int
    int maxVal = std::numeric_limits<int>::min();

    for (const auto& row : matrix) {
        for (int val : row) {
            if (val > maxVal) {
                maxVal = val;  // update maxVal if current element is greater
            }
        }
    }

    return maxVal;
}
```


## Examples
```
Input: mat[4][4] = {{1, 2, 3, 4},
                    {25, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};
Output: 25
```

```
Input: mat[3][4] = {{9, 8, 7, 6},
                    {5, 4, 3, 2},
                    {1, 0, 12, 45}};
Output: 45
```
