***Problem:***
```
You are given an m x n integer matrix matrix with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.
```



***Complexity:***
```
       Time Complexity: O(log(m * n))
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Map mid to 2D indices
            int row = mid / n;
            int col = mid % n;
            int midValue = matrix[row][col];
            
            if (midValue == target) {
                return true;  // Found target
            } else if (midValue < target) {
                left = mid + 1;  // Search right half
            } else {
                right = mid - 1; // Search left half
            }
        }
        
        return false; // Not found
    }
};
```


***Testcases:***
```
Input: matrix =
[[1,3,5,7],
[10,11,16,20],
[23,30,34,60]],

target = 3
Output: true
```

```
Input: matrix =
[[1,3,5,7],
[10,11,16,20],
[23,30,34,60]],

target = 13
Output: false
```
