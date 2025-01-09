Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough







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
