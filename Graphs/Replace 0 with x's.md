# Replace 0 with x's

```cpp
class Solution {

public:

    // Helper function for flood fill

    void floodFill(vector<vector<char>>& screen, int x, int y, char targetC, char newC) {

        // Base cases: Out of bounds or not the target color

        if (x < 0 || x >= screen.size() || y < 0 || y >= screen[0].size() || screen[x][y] != targetC)

            return;

        

        // Change the current cell to the new color

        screen[x][y] = newC;

        

        // Recursive calls for adjacent cells

        floodFill(screen, x + 1, y, targetC, newC);

        floodFill(screen, x - 1, y, targetC, newC);

        floodFill(screen, x, y + 1, targetC, newC);

        floodFill(screen, x, y - 1, targetC, newC);

    }

    

    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {

        // Perform flood fill for boundary cells

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < m; ++j) {

                // If a boundary cell is 'O', start flood fill

                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && mat[i][j] == 'O') {

                    floodFill(mat, i, j, 'O', '-'); // Replace 'O' with '-' as temporary marker

                }

            }

        }

        

        // Finalize the filled regions

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < m; ++j) {

                if (mat[i][j] == 'O') {

                    mat[i][j] = 'X'; // Remaining 'O' cells are changed to 'X'

                } else if (mat[i][j] == '-') {

                    mat[i][j] = 'O'; // Revert temporary markers '-' back to 'O'

                }

            }

        }

        

        return mat;

    }

};

```
