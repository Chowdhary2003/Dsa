***Problem :***
```
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.
```

***Complexity :***
```
Time Complexity: O(rows + cols) 
Space Complexity: O(1)
```


***Code :***
```cpp
bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;  // Guard clause for empty matrix
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int row = 0, col = cols - 1;  // Start from top-right corner
    
    while (row < rows && col >= 0) {
        int current = matrix[row][col];
        
        if (current == target) {
            return true;  // Target found
        } else if (current > target) {
            --col;  // Move left
        } else {
            ++row;  // Move down
        }
    }
    
    return false;  // Target not found
}
```

***Testcases :***
```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
```

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
```
