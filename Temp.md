Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough




Binary Search
```cpp
int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevent overflow

        if (nums[mid] == target) {
            return mid;  // Target found
        } else if (nums[mid] < target) {
            left = mid + 1;  // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }

    return -1;  // Target not found
}

```






Floor in a Sorted Array

```cpp
int findFloor(const std::vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    int floorIndex = -1;  // Initialize the floor index as -1

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow

        if (arr[mid] == k) {
            return mid;  // The element equals k, so it's the floor
        } else if (arr[mid] < k) {
            floorIndex = mid;  // Update the floor index
            low = mid + 1;     // Search the right half for a potentially larger floor
        } else {
            high = mid - 1;    // Search the left half for elements less than k
        }
    }

    return floorIndex;  // Return the largest index where arr[index] <= k, or -1 if no such element exists
}



```





Ceil The Floor

```cpp
std::vector<int> findFloorAndCeil(const std::vector<int>& arr, int x) {
    int floorValue = -1;  // Initialize floor to -1 (indicating not found)
    int ceilValue = -1;   // Initialize ceil to -1 (indicating not found)
    
    // Loop through the array to find the floor and ceil
    for (int num : arr) {
        if (num <= x) {
            floorValue = std::max(floorValue, num);  // Update floor if num <= x
        }
        if (num >= x) {
            if (ceilValue == -1 || num < ceilValue) {  // Update ceil if num >= x
                ceilValue = num;
            }
        }
    }

    // Return floor and ceil as a vector
    return {floorValue, ceilValue};
}


```



Search Insert Position
```cpp

int searchInsertPosition(const std::vector<int>& nums, int target) {
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


 Ceil The Floor


```cpp



pair<int, int> findFloorAndCeiling(const vector<int>& a, int x) {
    int low = 0, high = a.size() - 1;
    int floor = -1, ceiling = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (a[mid] == x) {
            // If the exact value is found, both floor and ceiling are `x`
            return {a[mid], a[mid]};
        } else if (a[mid] < x) {
            // If mid is less than x, it could be a potential floor
            floor = a[mid];
            low = mid + 1;
        } else {
            // If mid is greater than x, it could be a potential ceiling
            ceiling = a[mid];
            high = mid - 1;
        }
    }
    
    return {floor, ceiling};
}

```



Find First and Last Position of Element in Sorted Array
```cpp

 vector<int> searchRange(vector<int>& nums, int target) {
        // Find the leftmost (first) position of target using binary search
        int left = binarySearch(nums, target, true);
        // If target is not found, return [-1, -1]
        if (left == nums.size() || nums[left] != target) {
            return {-1, -1};
        }
        // Find the rightmost (last) position of target using binary search
        int right = binarySearch(nums, target, false);
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



Number of occurrence

```cpp

// Function to find the leftmost index of target using binary search
int findLeftmost(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Search the left half to find the first occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// Function to find the rightmost index of target using binary search
int findRightmost(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Search the right half to find the last occurrence
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// Function to count the occurrences of target in the array
int countOccurrences(const vector<int>& arr, int target) {
    int leftmost = findLeftmost(arr, target);
    if (leftmost == -1) {
        return 0; // Target not found
    }
    int rightmost = findRightmost(arr, target);
    return rightmost - leftmost + 1;
}


```



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
