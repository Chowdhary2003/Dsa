***Problem:***
```
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The '.' character indicates empty cells.
```



***Complexity:***
```
       Time Complexity: O(9^(N))
       Space Complexity: O(N) + O(1)
```



***Code:***
```cpp
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        SudokuSolver solver(board);
        solver.solve();
    }

private:
    class SudokuSolver {
    public:
        static constexpr int N = 9;

        explicit SudokuSolver(vector<vector<char>>& b) : board(b) {
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (board[r][c] != '.') {
                        int num = board[r][c] - '0';
                        rows[r][num] = true;
                        cols[c][num] = true;
                        blocks[getBlockIndex(r, c)][num] = true;
                    }
                }
            }
        }

        bool solve() {
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (board[r][c] == '.') {
                        for (int num = 1; num <= 9; ++num) {
                            if (canPlace(r, c, num)) {
                                placeNumber(r, c, num);
                                if (solve()) return true;
                                removeNumber(r, c, num);
                            }
                        }
                        return false;  // backtrack
                    }
                }
            }
            return true;  // solved
        }

    private:
        vector<vector<char>>& board;
        array<array<bool, N + 1>, N> rows{};   // rows[r][num]
        array<array<bool, N + 1>, N> cols{};   // cols[c][num]
        array<array<bool, N + 1>, N> blocks{}; // blocks[blockIndex][num]

        static int getBlockIndex(int r, int c) {
            return (r / 3) * 3 + (c / 3);
        }

        bool canPlace(int r, int c, int num) {
            int block = getBlockIndex(r, c);
            return !rows[r][num] && !cols[c][num] && !blocks[block][num];
        }

        void placeNumber(int r, int c, int num) {
            board[r][c] = '0' + num;
            rows[r][num] = true;
            cols[c][num] = true;
            blocks[getBlockIndex(r, c)][num] = true;
        }

        void removeNumber(int r, int c, int num) {
            board[r][c] = '.';
            rows[r][num] = false;
            cols[c][num] = false;
            blocks[getBlockIndex(r, c)][num] = false;
        }
    };
};
```


***Testcases:***

![image](https://github.com/user-attachments/assets/e1d3cd3b-85b5-43f7-ba82-207ee1f4f0ca)
