***Problem:***
```
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
```



***Complexity:***
```
       Time Complexity: O(n²)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>  // for std::swap and std::reverse

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix in-place
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row in-place
    for (auto& row : matrix) {
        std::reverse(row.begin(), row.end());
    }
}
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/3613a0b7-756e-4766-bfc9-bac8e95d89cf" width="500" />



***Testcases :***
```
Starting Matrix:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

After transposing, the matrix becomes:
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16



Reverse each row of the transposed matrix.
First row [1, 5, 9, 13] becomes [13, 9, 5, 1]
Second row [2, 6, 10, 14] becomes [14, 10, 6, 2]
Third row [3, 7, 11, 15] becomes [15, 11, 7, 3]
Fourth row [4, 8, 12, 16] becomes [16, 12, 8, 4]

After reversing the rows, the matrix becomes:
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4
```

----------

***Problem:***
```
You are given a square matrix of non-negative integers of size 'N x N'. Your task is to rotate that array by 90 degrees in an anti-clockwise direction without using any extra space.
```



***Complexity:***
```
       Time Complexity: Transposition: O(N²), Column reversal: O(N²)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm> // for std::swap
using namespace std;

// Rotates the matrix 90 degrees anti-clockwise in-place
void rotateMatrixAntiClockwise(vector<vector<int>>& matrix) {
    int N = matrix.size();
    if (N == 0) return;

    // Step 1: Transpose the matrix
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each column (top to bottom)
    for (int col = 0; col < N; ++col) {
        for (int row = 0, revRow = N - 1; row < revRow; ++row, --revRow) {
            swap(matrix[row][col], matrix[revRow][col]);
        }
    }
}
```


***Testcases:***
```
For given 2D array :

    [    [ 1,  2,  3 ],
         [ 4,  5,  6 ],
         [ 7,  8,  9 ]  ]

After 90 degree rotation in anti clockwise direction, it will become:

    [   [ 3,  6,  9 ],
        [ 2,  5,  8 ],
        [ 1,  4,  7 ]   ]
```

```
Sample Input 1:
3
1  2  3
4  5  6
7  8  9
4
1  2  3  4 
5  6  7  8 
9 10 11 12 
13 14 15 16
Sample Output 1:
3  6  9 
2  5  8 
1  4  7
4  8 12 16 
3  7 11 15 
2  6 10 14 
1  5  9 13
Explanation of Input 1:
(i) The array has been rotated by 90 degrees in an anticlockwise direction as the first row is now the first column inverted and so on for second and third rows.

(ii) The array has been rotated by 90 degrees in an anticlockwise direction as the first row is now first column inverted and so on for second, third and fourth rows.
```

```
Sample Input 2:
3
7  4  1 
8  5  2 
9  6  3
4
13  9  5  1 
14  10  6  2 
15 11 7 3 
16 12 8 4
Sample Output 2:
1  2  3
4  5  6
7  8  9
1  2  3  4 
5  6  7  8 
9 10 11 12 
13 14 15 16
```
