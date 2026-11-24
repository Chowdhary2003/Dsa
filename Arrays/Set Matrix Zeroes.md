***Problem:***
```
You are given an N x M integer matrix. Your task is to modify this matrix in place so that if any cell contains the value 0, then all cells in the same row and column as that cell should also be set to 0.

Requirements:
If a cell in the matrix has the value 0, set all other cells in that cell's row and column to 0.
You should perform this modification in place (without using additional matrices).

You must do it in place.
```

or

```
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
```


***Complexity:***
```
       Time Complexity: O(m × n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Flags to indicate whether first row and first column should be zeroed
    bool firstRowZero = false, firstColZero = false;

    // Step 1: Check if first row or first column has any zeros
    // Check if first column needs to be zero
    for (int i = 0; i < rows; ++i)
        if (matrix[i][0] == 0)
            firstColZero = true;

    // Check if first row needs to be zero
    for (int j = 0; j < cols; ++j)
        if (matrix[0][j] == 0)
            firstRowZero = true;

    // Step 2: Use first row and column to mark zeros
    // Use first row and column as markers
    for (int i = 1; i < rows; ++i)
        for (int j = 1; j < cols; ++j)
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;  // Mark row
                matrix[0][j] = 0;  // Mark column
            }

    // Step 3: Set matrix cells to zero based on markers
    for (int i = 1; i < rows; ++i)
        for (int j = 1; j < cols; ++j)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    // Step 4: Zero out first row and column if needed
    // Zero the first column if needed
    if (firstColZero)
        for (int i = 0; i < rows; ++i)
            matrix[i][0] = 0;

    // Zero the first row if needed
    if (firstRowZero)
        for (int j = 0; j < cols; ++j)
            matrix[0][j] = 0;
}
```


***Testcases:***
```
For Example:

If the given grid is this:
[7, 19, 3]
[4, 21, 0]

Then the modified grid will be:
[7, 19, 0]
[0, 0,  0]
```

```
Sample Input 1 :
2 3
7 19 3
4 21 0
3 3
1 2 3
4 0 6
7 8 9
Sample Output 1 :
7 19 0
0 0 0
1 0 3
0 0 0
7 0 9
Explanation For Sample Input 1 :
For First Case - Similar to the example explained above. 

For Second Case - 
Only the cell (2,2) has zero. So all the elements of the second row and second column are changed to zeros.
```

```
Sample Input 2 :
4 2
1 0
2 7
3 0
4 8
3 3
0 2 3
1 0 3
1 2 0
Sample Output 2 :
0 0
2 0
0 0
4 0
0 0 0
0 0 0
0 0 0
```

***Testcases :***



<img src="https://github.com/user-attachments/assets/b933d557-48c4-4b9c-b9de-258502d04618" width="500" />
