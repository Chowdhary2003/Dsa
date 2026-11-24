***Problem:***
```
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <iostream>

class Solution {
public:
    int trap(const std::vector<int>& height) {
        int n = static_cast<int>(height.size());
        if (n < 3) return 0; // Less than 3 bars can't trap water

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int trappedWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // If current left bar is lower
                if (height[left] >= leftMax) {
                    leftMax = height[left]; // Update left max
                } else {
                    trappedWater += leftMax - height[left]; // Water trapped at left
                }
                ++left;
            } else {
                // Current right bar is lower or equal
                if (height[right] >= rightMax) {
                    rightMax = height[right]; // Update right max
                } else {
                    trappedWater += rightMax - height[right]; // Water trapped at right
                }
                --right;
            }
        }
        return trappedWater;
    }
};
```


***Testcases:***

![Screenshot 2025-06-30 083154](https://github.com/user-attachments/assets/a5c4025d-9637-4efb-a71d-a94c06261a87)
