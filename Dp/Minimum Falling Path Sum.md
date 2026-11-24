***Problem:***
```
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // If the matrix is empty, return 0
    if (n == 0) return 0;
    
    // Initialize the first row of dp as the first row of matrix
    vector<int> prev = matrix[0];
    
    // Process rows starting from the second row
    for (int r = 1; r < n; ++r) {
        vector<int> curr(n, INT_MAX);  // Current row dp array
        
        for (int c = 0; c < n; ++c) {
            // Calculate the minimum sum for the current element
            // The valid columns from the previous row are c-1, c, c+1
            if (c > 0) curr[c] = min(curr[c], prev[c-1] + matrix[r][c]);
            curr[c] = min(curr[c], prev[c] + matrix[r][c]);
            if (c < n - 1) curr[c] = min(curr[c], prev[c+1] + matrix[r][c]);
        }
        
        // Move the current row as the previous row for the next iteration
        prev = curr;
    }
    
    // Return the minimum value from the last row of dp
    return *min_element(prev.begin(), prev.end());
}
```


***Testcases:***



![Screenshot 2025-05-20 191054](https://github.com/user-attachments/assets/b9dbc855-7fd7-4943-8f7a-d9e8441c9b8b)



