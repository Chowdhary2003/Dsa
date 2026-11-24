***Problem:***
```
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

    int findDuplicate(const std::vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Finding the intersection point of the two runners in the cycle
        do {
            slow = nums[slow];         // move slow by 1 step
            fast = nums[nums[fast]];   // move fast by 2 steps
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
```


***Testcases:***
```
Input: nums = [1,3,4,2,2]
Output: 2
```

```
Input: nums = [3,1,3,4,2]
Output: 3
```

```
Input: nums = [3,3,3,3,3]
Output: 3
```
