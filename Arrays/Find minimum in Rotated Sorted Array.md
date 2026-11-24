***Problem :***
```
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.

Given the sorted rotated array nums of unique elements, return the minimum element of this array.
```

***Complexity :***
```
Time Complexity: O(log n) 
Space Complexity: O(1)
```


***Code :***
```cpp
int findMin(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // If the middle element is greater than the rightmost element, 
        // the minimum is in the right half.
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            // Otherwise, the minimum is in the left half (or mid itself).
            right = mid;
        }
    }
    
    // At the end of the loop, left == right, which is the index of the minimum element.
    return nums[left];
}
```

***Testcases :***
```
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
```
```
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
```
```
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
```
