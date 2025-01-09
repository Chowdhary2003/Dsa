Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough




Search in Rotated Sorted Array
```cpp

int search(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if mid is the target
        if (nums[mid] == target) {
            return mid;
        }
        
        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;  // Search in the left half
            } else {
                left = mid + 1;   // Search in the right half
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;   // Search in the right half
            } else {
                right = mid - 1;  // Search in the left half
            }
        }
    }
    
    // Return -1 if the target is not found
    return -1;
}

```



Search in Rotated Sorted Array II
```cpp

bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // If we find the target, return true
        if (nums[mid] == target) {
            return true;
        }
        
        // Handle the case where we have duplicates (cannot decide the sorted side)
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        }
        // Left half is sorted
        else if (nums[left] <= nums[mid]) {
            // Check if the target lies in the sorted left half
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Narrow search to the left half
            } else {
                left = mid + 1;  // Narrow search to the right half
            }
        }
        // Right half is sorted
        else {
            // Check if the target lies in the sorted right half
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Narrow search to the right half
            } else {
                right = mid - 1; // Narrow search to the left half
            }
        }
    }
    
    return false; // Target is not in the array
}

```


Find Minimum in Rotated Sorted Array


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




Find Kth Rotation

```cpp
int findRotationCount(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    // Edge case: if the array has only one element, it's already sorted and not rotated.
    if (arr.size() == 1) return 0;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the middle element is greater than the rightmost element,
        // the smallest element is to the right of mid.
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            // Otherwise, the smallest element is to the left of mid, including mid.
            right = mid;
        }
    }

    // At the end of the loop, 'left' will point to the smallest element.
    return left;
}

```





Single element in a Sorted Array

```cpp

int singleNonDuplicate(std::vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Ensure mid is even to easily compare with the next element
        if (mid % 2 == 1) {
            mid--;
        }

        // If pair is valid, move to the right half
        if (nums[mid] == nums[mid + 1]) {
            low = mid + 2;
        } else {
            high = mid;
        }
    }

    // When low == high, we've found the single element
    return nums[low];
}

```






  Find Peak Element

  
```cpp

int findPeakElement(const std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if mid is a peak element
        if (nums[mid] > nums[mid + 1]) {
            // Peak is in the left half (including mid)
            right = mid;
        } else {
            // Peak is in the right half
            left = mid + 1;
        }
    }

    // At the end, left == right, and that will be the peak index
    return left;
}

```
