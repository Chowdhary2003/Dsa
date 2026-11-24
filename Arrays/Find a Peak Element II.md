***Problem :***
```
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
```

***Complexity :***
```
Time Complexity: O(m . log n) 
Space Complexity: O(1)
```


***Code :***
```cpp
// Helper function to find the peak element in the middle column
int findMaxInColumn(const vector<vector<int>>& mat, int col) {
    int maxRow = 0;
    int m = mat.size();
    
    for (int i = 1; i < m; ++i) {
        if (mat[i][col] > mat[maxRow][col]) {
            maxRow = i;
        }
    }
    
    return maxRow;
}

// Function to find a peak element
vector<int> findPeakElement(const vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    
    int left = 0, right = n - 1;
    
    // Binary search on columns
    while (left <= right) {
        int midCol = left + (right - left) / 2;
        
        // Find the row with the maximum element in the middle column
        int maxRow = findMaxInColumn(mat, midCol);
        
        // Compare the middle element with its neighbors
        int leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
        int rightVal = (midCol < n - 1) ? mat[maxRow][midCol + 1] : -1;
        
        // If the current element is greater than both neighbors, it's a peak
        if (mat[maxRow][midCol] >= leftVal && mat[maxRow][midCol] >= rightVal) {
            return {maxRow, midCol};
        }
        // If left neighbor is larger, move search to the left half
        else if (leftVal > mat[maxRow][midCol]) {
            right = midCol - 1;
        }
        // If right neighbor is larger, move search to the right half
        else {
            left = midCol + 1;
        }
    }
    
    return {}; // This should never be reached since the problem guarantees a peak
}
```

***Testcases :***
```
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
```


```
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
```
