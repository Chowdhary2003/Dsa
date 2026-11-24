***Problem:***
```
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
```



***Complexity:***
```
       Time Complexity: O(log n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>

int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        // Prevent overflow
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;  // Found target
        } 
        else if (nums[mid] < target) {
            left = mid + 1;  // Search right half
        } 
        else {
            right = mid - 1;  // Search left half
        }
    }
    return -1;  // Target not found
}
```


***Testcases:***
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```
