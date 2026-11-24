***Problem:***
```
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
- 0 <= j <= nums[i] and
- i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
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
#include <iostream>

int jump(vector<int>& nums) {
    int n = nums.size();
    
    // Base case: if the array length is 1, no jumps are needed
    if (n == 1) return 0;

    int jumps = 0;            // Count of jumps
    int farthest = 0;         // The farthest index we can reach
    int end_of_jump = 0;      // End of current jump range

    // Traverse through the array
    for (int i = 0; i < n - 1; ++i) {
        // Update the farthest we can reach from current index
        farthest = max(farthest, i + nums[i]);

        // If we've reached the end of the current jump range
        if (i == end_of_jump) {
            // Make a jump to the farthest reachable point
            jumps++;
            end_of_jump = farthest;
            
            // If we've reached or surpassed the last index, we're done
            if (end_of_jump >= n - 1) {
                break;
            }
        }
    }
    return jumps;
}
```


***Testcases:***
```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

```
Input: nums = [2,3,0,1,4]
Output: 2
```
