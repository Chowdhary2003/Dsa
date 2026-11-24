***Problem :***
```
You are given a 2D binary array arr[][] consisting of only 1s and 0s.
Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s.
 If no such row exists, return -1.
```

> [!Note]
> The array follows 0-based indexing.
> The number of rows and columns in the array are denoted by n and m respectively.


***Complexity :***
```
Time Complexity: O(n . log m) 
Space Complexity: O(1)
```


***Code :***
```cpp
// Function to find the index of the first row with the maximum number of 1s
int rowWithMax1s(const vector<vector<int>>& arr) {
    int n = arr.size();  // number of rows
    int m = arr[0].size();  // number of columns
    
    int max_row_index = -1;  // To store the row index with the maximum 1s
    int max_ones = -1;  // To store the count of maximum 1s in any row
    
    // Iterate through each row
    for (int i = 0; i < n; ++i) {
        // Binary search to find the first 1 in the current row
        int left = 0, right = m - 1;
        
        // We perform binary search in each row
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If we find 1, we move left to find the first 1
            if (arr[i][mid] == 1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // If left is within bounds, it gives us the number of 1s in the row
        int ones_in_row = m - left;
        
        // Update max_ones and max_row_index if this row has more 1s
        if (ones_in_row > max_ones) {
            max_ones = ones_in_row;
            max_row_index = i;
        }
    }
    
    return max_row_index;  // Return the index of the row with maximum 1s
}
```

***Testcases :***
```
Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.
```

```
Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
```

```
Input: arr[][] = [[0,0], [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.
```
