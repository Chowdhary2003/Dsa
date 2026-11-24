***Problem:***
```
Given an m x n matrix, return all elements of the matrix in spiral order.
```



***Complexity:***
```
       Time Complexity: O(m*n)
       Space Complexity: O(m*n)
```



***Code:***
```cpp
#include <vector>
using std::vector;

vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
        return {};

    int top = 0;
    int bottom = static_cast<int>(matrix.size()) - 1;
    int left = 0;
    int right = static_cast<int>(matrix[0].size()) - 1;
    
    vector<int> result;
    result.reserve((bottom + 1) * (right + 1)); // reserve output capacity
    
    while (top <= bottom && left <= right) {
        // Traverse from left to right on the current top row
        for (int col = left; col <= right; ++col)
            result.push_back(matrix[top][col]);
        ++top;  // Move the top boundary down
        
        // Traverse from top to bottom on the current right column
        for (int row = top; row <= bottom; ++row)
            result.push_back(matrix[row][right]);
        --right;  // Move the right boundary left
        
        if (top <= bottom) {
            // Traverse from right to left on the current bottom row
            for (int col = right; col >= left; --col)
                result.push_back(matrix[bottom][col]);
            --bottom;  // Move the bottom boundary up
        }
        
        if (left <= right) {
            // Traverse from bottom to top on the current left column
            for (int row = bottom; row >= top; --row)
                result.push_back(matrix[row][left]);
            ++left;  // Move the left boundary right
        }
    }
    
    return result;
}
```


***Testcases:***
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```
