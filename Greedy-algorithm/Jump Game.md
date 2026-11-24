***Problem:***
```
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

class Solution {
public:
    bool canJump(const vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (i > farthest) return false; // Cannot reach this index
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1) return true; // Can reach or surpass last index
        }
        
        return true; // Handles single-element case like [0]
    }
};
```


***Testcases:***
```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```
