***Problem:***
```
For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)

 Mind that every element will be printed only once.
```



***Complexity:***
```
       Time Complexity: O(N*M)
       Space Complexity: O(N*M)
```



***Code:***
```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty() || matrix[0].empty()) return result;

    int top = 0;
    int bottom = (int)matrix.size() - 1;
    int left = 0;
    int right = (int)matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int col = left; col <= right; ++col) {
            result.push_back(matrix[top][col]);
        }
        ++top; // shrink top boundary

        // Traverse downwards along the right column
        for (int row = top; row <= bottom; ++row) {
            result.push_back(matrix[row][right]);
        }
        --right; // shrink right boundary

        // Check if we still have rows to traverse bottom row
        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int col = right; col >= left; --col) {
                result.push_back(matrix[bottom][col]);
            }
            --bottom; // shrink bottom boundary
        }

        // Check if we still have columns to traverse left column
        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int row = bottom; row >= top; --row) {
                result.push_back(matrix[row][left]);
            }
            ++left; // shrink left boundary
        }
    }

    return result;
}
```


***Testcases:***



<img src="https://github.com/user-attachments/assets/8c9bde2f-5e10-4353-be8f-af72bd245623" width="500" />


```
Sample Input 1:
1
4 4 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16
Sample Output 1:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
```

```
Sample Input 2:
2
3 3 
1 2 3 
4 5 6 
7 8 9
3 1
10
20
30
Sample Output 2:
1 2 3 6 9 8 7 4 5 
10 20 30 
```
