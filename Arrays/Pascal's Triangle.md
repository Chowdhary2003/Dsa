***Problem:***
```
Given an integer numRows, return the first numRows of Pascal's triangle.
```

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
![Screenshot 2024-12-30 141717](https://github.com/user-attachments/assets/2344284d-6e9a-485e-9e7f-55c936bc7a4e)


***Complexity:***
```
       Time Complexity: O(numRows²)
       Space Complexity: O(numRows²)
```



***Code:***
```cpp
#include <vector>

std::vector<std::vector<int>> generatePascalTriangle(int numRows) {
    std::vector<std::vector<int>> triangle;
    if (numRows == 0) return triangle;

    for (int row = 0; row < numRows; ++row) {
        std::vector<int> current(row + 1, 1);  // Initialize row with 1s

        // Fill in the middle elements using previous row
        for (int j = 1; j < row; ++j) {
            current[j] = triangle[row - 1][j - 1] + triangle[row - 1][j];
        }

        triangle.emplace_back(std::move(current)); // efficient move instead of copy
    }

    return triangle;
}
```


***Testcases:***
```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

```
Input: numRows = 1
Output: [[1]]
```



