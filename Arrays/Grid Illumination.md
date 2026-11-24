***Problem:***
```
There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.

You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.

When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.

You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].

Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.
```



***Complexity:***
```
       Time Complexity: O(L + Q log L) in worst case.
       Space Complexity: O(L)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        using ll = long long;
        constexpr int dirs[9][2] = {{0,0}, {0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};

        // Maps to count lamps illuminating each row, column, diagonal
        unordered_map<int, int> rowMap, colMap, diagMap, antiDiagMap;
        set<pair<int, int>> lampSet;

        auto hash = [n](int r, int c) -> ll {
            return static_cast<ll>(r) * n + c;
        };

        for (const auto& lamp : lamps) {
            int r = lamp[0], c = lamp[1];
            if (!lampSet.insert({r, c}).second) continue; // Skip duplicates
            ++rowMap[r];
            ++colMap[c];
            ++diagMap[r - c];
            ++antiDiagMap[r + c];
        }

        vector<int> result;
        for (const auto& q : queries) {
            int r = q[0], c = q[1];

            // Check if illuminated
            if (rowMap[r] > 0 || colMap[c] > 0 || diagMap[r - c] > 0 || antiDiagMap[r + c] > 0) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }

            // Turn off lamp at (r, c) and adjacent cells
            for (const auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (lampSet.count({nr, nc})) {
                    lampSet.erase({nr, nc});
                    --rowMap[nr];
                    --colMap[nc];
                    --diagMap[nr - nc];
                    --antiDiagMap[nr + nc];
                }
            }
        }

        return result;
    }
};
```


***Testcases:***

<img width="1541" height="1283" alt="Screenshot 2025-07-22 090423" src="https://github.com/user-attachments/assets/1dfd8ee6-2602-45b6-8686-6ef78e72f2a7" />


<img width="1496" height="617" alt="Screenshot 2025-07-22 090436" src="https://github.com/user-attachments/assets/591cf435-47ba-44e2-a66b-986e1c1143df" />


```
Input: n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
Output: [1,1,0]
```
