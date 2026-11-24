***Problem:***
```
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
    // Start from the second-last row and move upwards
    for (int row = triangle.size() - 2; row >= 0; --row) {
        // Update each element in the row to be the minimum of the two adjacent elements in the row below
        for (int col = 0; col <= row; ++col) {
            triangle[row][col] += std::min(triangle[row + 1][col], triangle[row + 1][col + 1]);
        }
    }

    // The top element now contains the minimum path sum
    return triangle[0][0];
}
```


***Testcases:***
```
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
```

```
Input: triangle = [[-10]]
Output: -10
```
