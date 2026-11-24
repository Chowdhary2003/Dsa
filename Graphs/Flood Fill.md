***Problem:***
```
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:
1. Begin with the starting pixel and change its color to color.
2. Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
3. Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
4. The process stops when there are no more adjacent pixels of the original color to update.

Return the modified image after performing the flood fill.
```



***Complexity:***
```
       Time Complexity: O(m × n) in worst case
       Space Complexity: O(m × n) in worst case
```



***Code:***
```cpp
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        const int m = image.size();
        const int n = image[0].size();
        const int originalColor = image[sr][sc];

        // No-op case: color is already what we want
        if (originalColor == color) return image;

        // Directions: up, down, left, right
        const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        stack<pair<int, int>> stk;
        stk.push({sr, sc});

        while (!stk.empty()) {
            auto [x, y] = stk.top();
            stk.pop();

            // Change color
            image[x][y] = color;

            for (const auto& [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Bounds check and color match
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == originalColor) {
                    stk.push({nx, ny});
                }
            }
        }

        return image;
    }
};
```


***Testcases:***

<img width="1164" height="1052" alt="Screenshot 2025-07-11 082031" src="https://github.com/user-attachments/assets/1de5bfba-9453-414f-a72e-e912d916665c" />


```
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

Output: [[0,0,0],[0,0,0]]

Explanation:

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
```
