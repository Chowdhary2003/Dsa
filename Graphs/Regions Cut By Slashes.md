***Problem:***
```
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.
```



***Complexity:***
```
       Time Complexity: O(N² * α(N²))
       Space Complexity: O(N²)
```



***Code:***
```cpp
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int regionsBySlashes(const vector<string>& grid) {
        int n = grid.size();
        int size = n * n * 4;  // 4 parts per cell
        vector<int> parent(size);

        // Initialize Union-Find structure
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }

        // Helper to find root of a component
        auto find = [&](int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]]; // path compression
                x = parent[x];
            }
            return x;
        };

        // Helper to union two components
        auto unite = [&](int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px != py) parent[px] = py;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = (i * n + j) * 4;
                char c = grid[i][j];

                // Internal connections
                if (c == ' ') {
                    // All parts connected
                    unite(base + 0, base + 1);
                    unite(base + 1, base + 2);
                    unite(base + 2, base + 3);
                } else if (c == '/') {
                    unite(base + 0, base + 3);
                    unite(base + 1, base + 2);
                } else if (c == '\\') {
                    unite(base + 0, base + 1);
                    unite(base + 2, base + 3);
                }

                // External connections with neighbors
                // Connect bottom of current to top of cell below
                if (i + 1 < n) {
                    int bottom = base + 2;
                    int top = ((i + 1) * n + j) * 4 + 0;
                    unite(bottom, top);
                }
                // Connect right of current to left of right cell
                if (j + 1 < n) {
                    int right = base + 1;
                    int left = (i * n + (j + 1)) * 4 + 3;
                    unite(right, left);
                }
            }
        }

        // Count number of distinct roots
        int regions = 0;
        for (int i = 0; i < size; ++i) {
            if (find(i) == i) ++regions;
        }
        return regions;
    }
};
```


***Testcases:***


<img src="https://github.com/user-attachments/assets/21e74e5c-5996-4065-a1cd-a83f9f6b096d" width="500" />


<img src="https://github.com/user-attachments/assets/d6e53e28-49c4-4e05-8430-41c01466b8b1" width="500" />

