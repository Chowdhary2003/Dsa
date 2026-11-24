***Problem:***
```
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(const std::vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        std::stack<int> st;  // stores indices of bars in ascending order
        int max_area = 0;

        for (int i = 0; i <= n; ++i) {
            // Use 0 as sentinel height after end for final calculation
            int curr_height = (i == n) ? 0 : heights[i];

            // While current bar is less than bar at stack top,
            // we can calculate the rectangle area for the bar at stack top
            while (!st.empty() && curr_height < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int left_index = st.empty() ? -1 : st.top();
                int width = i - left_index - 1;  // width between current index and previous smaller bar

                max_area = std::max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }
};
```


***Testcases:***

<img src="https://github.com/user-attachments/assets/37a82ec3-187d-4483-baed-35cfb14eda42" width="500" />



<img src="https://github.com/user-attachments/assets/ed1d0a0d-40cf-4234-9601-99bf2c431999" width="500" height="500" />


