***Problem :***
```
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.
```

***Complexity :***
```
Time Complexity: O(log n) 
Space Complexity: O(1)
```


***Code :***
```cpp

int searchInsertPosition(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is found, return its index
        if (nums[mid] == target) {
            return mid;
        }
        // If the target is larger, search in the right half
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller, search in the left half
        else {
            right = mid - 1;
        }
    }

    // If not found, 'left' is the correct insertion position
    return left;
}
```

***Testcases :***
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```
```
Input: nums = [1,3,5,6], target = 2
Output: 1
```
```
Input: nums = [1,3,5,6], target = 7
Output: 4
```
