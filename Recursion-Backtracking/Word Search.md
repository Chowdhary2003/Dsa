***Problem:***
```
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
```



***Complexity:***
```
       Time Complexity: O(m * n * 4^k), where k = word.length()
       Space Complexity: O(k)
```



***Code:***
```cpp
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();

        // Lambda for DFS with backtracking
        function<bool(int, int, int)> dfs = [&](int row, int col, int idx) -> bool {
            // If all chars matched
            if (idx == (int)word.size()) return true;

            // Boundary and character checks
            if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[idx]) 
                return false;

            // Mark cell as visited by temporarily changing char
            char temp = board[row][col];
            board[row][col] = '#';  // any sentinel char that won't match word chars

            // Explore neighbors
            bool found = dfs(row + 1, col, idx + 1) ||
                         dfs(row - 1, col, idx + 1) ||
                         dfs(row, col + 1, idx + 1) ||
                         dfs(row, col - 1, idx + 1);

            // Backtrack
            board[row][col] = temp;

            return found;
        };

        // Try DFS from every cell matching word[0]
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
```


***Testcases:***

<img width="945" height="719" alt="Screenshot 2025-07-11 090302" src="https://github.com/user-attachments/assets/60b0be47-b9f3-4b52-b4c4-b8ae41dc5dd7" />

<img width="945" height="713" alt="Screenshot 2025-07-11 090312" src="https://github.com/user-attachments/assets/260180b3-9ac6-4dda-a591-4d9fec26ab51" />

<img width="931" height="731" alt="Screenshot 2025-07-11 090320" src="https://github.com/user-attachments/assets/dfb22548-9a78-4a08-a5e3-f42227502164" />
