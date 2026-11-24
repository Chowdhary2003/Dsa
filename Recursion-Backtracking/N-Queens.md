***Problem:***
```
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
```



***Complexity:***
```
       Time Complexity: O(n!) Worst-case time
       Space Complexity:  O(n), O(n^2) for storing all boards in results
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        
        // Track columns and diagonals usage
        vector<bool> cols(n, false);                    // columns occupied
        vector<bool> diag1(2 * n - 1, false);           // row + col
        vector<bool> diag2(2 * n - 1, false);           // row - col + n -1

        backtrack(0, n, board, cols, diag1, diag2, solutions);
        return solutions;
    }

private:
    void backtrack(int row, int n, vector<string>& board, 
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& solutions) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            int d1 = row + col;
            int d2 = row - col + n - 1;
            if (cols[col] || diag1[d1] || diag2[d2]) 
                continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = true; diag1[d1] = true; diag2[d2] = true;

            backtrack(row + 1, n, board, cols, diag1, diag2, solutions);

            // Backtrack
            board[row][col] = '.';
            cols[col] = false; diag1[d1] = false; diag2[d2] = false;
        }
    }
};
```


***Testcases:***

![Screenshot 2025-07-02 082101](https://github.com/user-attachments/assets/46dc07db-80e6-4a36-a43e-fb2d5279ad76)


```
Input: n = 1
Output: [["Q"]]
```
