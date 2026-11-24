***Problem:***
```
You are given a set of some types of rectangular 3-D boxes, where the ith box has height, width, and length height[i], width[i], and length[i] respectively. You have to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base. It is also allowable to use multiple instances of the same type of box. Your task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

Note: Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.
```



***Complexity:***
```
       Time Complexity: O(n²)
       Space Complexity: O(n) for DP array, O(n) for box rotations.
```



***Code:***
```cpp
class Solution {
public:
    struct Box {
        int length, width, height;
        
        Box(int l, int w, int h) {
            length = std::max(l, w);
            width = std::min(l, w);
            height = h;
        }

        int baseArea() const {
            return length * width;
        }
    };

    static bool compare(const Box& a, const Box& b) {
        return a.baseArea() > b.baseArea();
    }

    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = height.size();
        vector<Box> allRotations;

        // Step 1: Generate all 3 valid rotations for each box
        for (int i = 0; i < n; ++i) {
            int h = height[i], w = width[i], l = length[i];

            // 3 rotations: choose one as height, others as base
            allRotations.emplace_back(l, w, h);
            allRotations.emplace_back(h, l, w);
            allRotations.emplace_back(w, h, l);
        }

        // Step 2: Sort boxes by base area (descending)
        sort(allRotations.begin(), allRotations.end(), compare);

        int m = allRotations.size();
        vector<int> dp(m);

        // Step 3: Apply DP to find max stack height ending at each box
        for (int i = 0; i < m; ++i) {
            dp[i] = allRotations[i].height; // height if used alone
            for (int j = 0; j < i; ++j) {
                if (allRotations[j].length > allRotations[i].length &&
                    allRotations[j].width > allRotations[i].width) {
                    dp[i] = std::max(dp[i], dp[j] + allRotations[i].height);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
```


***Testcases:***
```
Input: height[] = [4, 1, 4, 10], width[] = [6, 2, 5, 12], length[] = [7, 3, 6, 32]
Output: 60
Explanation: One way of placing the boxes isas follows in the bottom to top manner: (Denoting the boxes in (l, w, h) manner)(12, 32, 10) (10, 12, 32) (6, 7, 4) (5, 6, 4) (4, 5, 6) (2, 3, 1) (1, 2, 3) Hence, the total height of this stack is 10 + 32 + 4 + 4 + 6 + 1 + 3 = 60. No other combination of boxes produces a height greater than this.
```

```
Input: height[] = [1, 4, 3], width[] = [2, 5, 4], length[] = [3, 6, 1]
Output: 15
Explanation: One way of placing the boxes is as follows in the bottom to top manner: (Denoting the boxes in (l, w, h) manner)(5, 6, 4) (4, 5, 6) (3, 4, 1), (2, 3, 1) (1, 2, 3).Hence, the total height of this stack is 4 + 6 + 1 + 1 + 3 = 15 No other combination of boxes produces a height greater than this.
```

```
Input: height[] = [3], width[] = [2], length[] = [6]
Output: 8
Explanation: One way of placing the boxes is as follows in the bottom to top manner: (Denoting the boxes in (l, w, h) manner)(6, 3, 2) (3, 2, 6). Hence, the total height of this stack is 2 + 6 = 8. No other combination of boxes produces a height greater than this.
```
