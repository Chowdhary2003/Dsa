***Problem:***
```
On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
```



***Complexity:***
```
       Time Complexity: O(N!)
       Space Complexity: O(N!)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Encode the 2x3 board as a string, e.g. "123450"
        string start;
        for (auto& row : board)
            for (int num : row)
                start += to_string(num);

        const string target = "123450";

        // Neighbors list: for each position in the string, indices where 0 can move
        vector<vector<int>> neighbors = {
            {1, 3},    // pos 0 neighbors
            {0, 2, 4}, // pos 1 neighbors
            {1, 5},    // pos 2 neighbors
            {0, 4},    // pos 3 neighbors
            {1, 3, 5}, // pos 4 neighbors
            {2, 4}     // pos 5 neighbors
        };

        queue<pair<string, int>> q; // {state, moves}
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [state, moves] = q.front();
            q.pop();

            if (state == target)
                return moves;

            int zeroPos = state.find('0');

            // Explore all valid swaps of zero with neighbors
            for (int nextPos : neighbors[zeroPos]) {
                string newState = state;
                swap(newState[zeroPos], newState[nextPos]);

                if (!visited.count(newState)) {
                    visited.insert(newState);
                    q.push({newState, moves + 1});
                }
            }
        }

        return -1; // Unsolvable
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/08ea637a-8df9-4b82-8bea-2550fe0e8f6a" width="500" />


<img src="https://github.com/user-attachments/assets/3360a1dd-60c6-420e-8371-bf3713384d58" width="500" />


