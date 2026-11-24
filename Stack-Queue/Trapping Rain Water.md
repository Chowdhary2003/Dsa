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
#include <algorithm>

int trap(const std::vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0; // At least 3 bars needed to trap water

    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    int waterTrapped = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= maxLeft) {
                maxLeft = height[left];
            } else {
                waterTrapped += maxLeft - height[left];
            }
            ++left;
        } else {
            if (height[right] >= maxRight) {
                maxRight = height[right];
            } else {
                waterTrapped += maxRight - height[right];
            }
            --right;
        }
    }

    return waterTrapped;
}
```


***Testcases:***


<img width="945" height="892" alt="Screenshot 2025-07-13 074704" src="https://github.com/user-attachments/assets/7b80e47a-56ad-46e0-90e2-68e8ca2e253d" />

