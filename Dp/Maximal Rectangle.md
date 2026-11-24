***Problem:***
```
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
```



***Complexity:***
```
       Time Complexity: O(rows * cols)
       Space Complexity: O(cols)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int largestRectangleArea(const vector<int>& heights) {
    stack<int> stk;
    int maxArea = 0;
    vector<int> extendedHeights = heights;
    extendedHeights.push_back(0);  // Add a 0 at the end to flush out remaining bars
    
    for (int i = 0; i < extendedHeights.size(); ++i) {
        while (!stk.empty() && extendedHeights[i] < extendedHeights[stk.top()]) {
            int height = extendedHeights[stk.top()];
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        stk.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> height(cols, 0);
    int maxArea = 0;
    
    for (int i = 0; i < rows; ++i) {
        // Build the height histogram for the current row
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }
        
        // Find the largest rectangle for the current histogram (current row's heights)
        maxArea = max(maxArea, largestRectangleArea(height));
    }
    
    return maxArea;
}
```


***Testcases:***

![Screenshot 2025-05-22 150910](https://github.com/user-attachments/assets/47417a93-6bd5-436b-a8e1-97817a50c9b2)
