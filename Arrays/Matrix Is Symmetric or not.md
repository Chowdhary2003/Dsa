
***Problem:***
```
You are given a square matrix, return true if the matrix is symmetric otherwise return false.

A symmetric matrix is that matrix whose transpose is equal to the matrix itself.
```



***Complexity:***
```
       Time Complexity: Best case: O(1) , Worst case: O(n²)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

bool isSymmetric(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Ensure matrix is square
    for (const auto& row : matrix) {
        if (row.size() != n) return false;
    }

    // Only compare elements above the main diagonal
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false; // Early exit on mismatch
            }
        }
    }

    return true;
}
```


***Testcases:***

![Screenshot 2025-06-09 085231](https://github.com/user-attachments/assets/edc86bae-57fc-4265-874e-43652a48e420)
