
***Problem :***
```
You are given a binary matrix (it contains only 0s and 1s) with dimensions ‘N * M’.
You need to find and return the sum of coverages of all zeros of the given matrix.

Coverage for a particular 0 is defined as the total number of ‘1s’ around it (i.e., immediate left, immediate right, immediate up, and immediate bottom positions).
```


***Complexity :***

```
    Time Complexity O(N*M)
    Space Complexity: O(1)
```

***Code :***

```cpp
#include <vector>
using namespace std;

int coverageOfMatrix(vector<vector<int>> &mat) {
    int n = mat.size();    // Number of rows
    int m = mat[0].size(); // Number of columns

    // This variable stores our answer.
    int ans = 0;

    // Iterate through each cell in the matrix.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // If the current cell is 1, skip it
            if (mat[i][j] == 1) {
                continue;
            }

            // Check the left neighbor (if it exists)
            if (j - 1 >= 0) {
                ans += mat[i][j - 1];
            }
            // Check the top neighbor (if it exists)
            if (i - 1 >= 0) {
                ans += mat[i - 1][j];
            }
            // Check the right neighbor (if it exists)
            if (j + 1 < m) {
                ans += mat[i][j + 1];
            }
            // Check the bottom neighbor (if it exists)
            if (i + 1 < n) {
                ans += mat[i + 1][j];
            }
        }
    }

    // Return the final answer.
    return ans;
}
```

***Testcases:***
```
Sample Input :
2 2

1 0
0 1

Sample Output :
4

Explanation of Input :
In the given matrix, there are 2 zeros. 
For the 0 at the 1st row, 2nd column position, coverage is 2(there is 1 adjacent top one and 1 adjacent right one).
For the 0 at the 2nd row, 2nd column the coverage is 2(there is 1 adjacent top one and 1 adjacent right one).

Hence the net coverage is 2 + 2 = 4.
```


```
Sample Input :
2 3

0 0 0
0 0 0

Sample Output :
0
```
