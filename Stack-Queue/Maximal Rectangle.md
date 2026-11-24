***Problem:***
```
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
```



***Complexity:***
```
       Time Complexity: O(m × n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
int largestRectangleInHistogram(const vector<int>& heights) {
    stack<int> st;  // store indices of bars
    int maxArea = 0;
    int n = static_cast<int>(heights.size());

    for (int i = 0; i <= n; ++i) {
        // Use 0 height at the end to flush remaining bars
        int h = (i == n) ? 0 : heights[i];

        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int rows = static_cast<int>(matrix.size());
    int cols = static_cast<int>(matrix[0].size());
    vector<int> heights(cols, 0);

    int maxArea = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleInHistogram(heights));
    }

    return maxArea;
}
```


***Testcases:***


<img width="735" height="975" alt="Screenshot 2025-07-28 080848" src="https://github.com/user-attachments/assets/a814241c-c102-48a1-8ee2-93e9111ef09e" />



```
Input: matrix = [["0"]]
Output: 0
```

```
Input: matrix = [["1"]]
Output: 1
```
