***Problem :***
```
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
```

***Complexity :***
```
Time Complexity: O(log n) 
Space Complexity: O(1)
```


***Code :***
```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    // Find the leftmost (first) position of target using binary search
    int left = binarySearch(nums, target, true);
    // If target is not found, return [-1, -1]
    if (left == nums.size() || nums[left] != target) {
        return {-1, -1};
    }
    // Find the rightmost (last) position of target using binary search
    int right = binarySearch(nums, target, false) - 1;
    return {left, right};
}

int binarySearch(const vector<int>& nums, int target, bool findLeft) {
    int low = 0, high = nums.size() - 1, result = nums.size();
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target || (findLeft && nums[mid] == target)) {
            high = mid - 1;
            result = mid;
        } else {
            low = mid + 1;
        }
    }
    return result;
}
```

***Testcases :***
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```
```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```
```
Input: nums = [], target = 0
Output: [-1,-1]
```
