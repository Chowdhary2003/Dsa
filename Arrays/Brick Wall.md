***Problem:***
```
There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.
```



***Complexity:***
```
       Time Complexity: O(n * m)
       Space Complexity: O(k)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int leastBricks(const std::vector<std::vector<int>>& wall) {
        std::unordered_map<long long, int> edgeCount; // use long long for key
        int maxEdges = 0;

        for (const auto& row : wall) {
            long long position = 0; // ⬅️ use 64-bit accumulator
            for (size_t i = 0; i < row.size() - 1; ++i) {
                position += row[i];
                ++edgeCount[position];
                maxEdges = std::max(maxEdges, edgeCount[position]);
            }
        }

        return static_cast<int>(wall.size()) - maxEdges;
    }
};
```


***Testcases:***

<img width="868" height="1015" alt="Screenshot 2025-07-22 085926" src="https://github.com/user-attachments/assets/9b41a58b-4d94-4bf0-913f-e8f83a8504ab" />


```
Input: wall = [[1],[1],[1]]
Output: 3
```
