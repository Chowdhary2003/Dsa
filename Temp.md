Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough






Count Inversions

```cpp

// Merge function that counts inversions while merging two halves
long long merge_and_count(std::vector<int>& arr, std::vector<int>& temp_arr, int left, int right) {
    if (left == right) {
        return 0; // Base case: no inversion in a single element
    }

    int mid = left + (right - left) / 2;
    long long inv_count = 0;

    // Count inversions in the left half, right half, and during merging
    inv_count += merge_and_count(arr, temp_arr, left, mid);
    inv_count += merge_and_count(arr, temp_arr, mid + 1, right);
    inv_count += merge(arr, temp_arr, left, mid, right);

    return inv_count;
}

// Merge function that merges two sorted subarrays and counts inversions
long long merge(std::vector<int>& arr, std::vector<int>& temp_arr, int left, int mid, int right) {
    int i = left;     // Starting index for left subarray
    int j = mid + 1;  // Starting index for right subarray
    int k = left;     // Starting index to be sorted
    long long inv_count = 0;

    // Merge two sorted subarrays
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp_arr[k++] = arr[i++];
        } else {
            temp_arr[k++] = arr[j++];
            inv_count += (mid - i + 1); // All remaining elements in left subarray form inversions with arr[j]
        }
    }

    // Copy remaining elements of the left subarray, if any
    while (i <= mid) {
        temp_arr[k++] = arr[i++];
    }

    // Copy remaining elements of the right subarray, if any
    while (j <= right) {
        temp_arr[k++] = arr[j++];
    }

    // Copy the sorted subarray back into the original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp_arr[i];
    }

    return inv_count;
}

// Function to count inversions in the array
long long count_inversions(std::vector<int>& arr) {
    std::vector<int> temp_arr(arr.size());
    return merge_and_count(arr, temp_arr, 0, arr.size() - 1);
}
```




Reverse Pairs

```cpp
class Solution {
public:
    // Main function to count reverse pairs
    int reversePairs(std::vector<int>& nums) {
        std::vector<int> temp(nums.size());
        return mergeSortAndCount(nums, temp, 0, nums.size() - 1);
    }
    
private:
    // Helper function to perform merge sort and count reverse pairs
    int mergeSortAndCount(std::vector<int>& nums, std::vector<int>& temp, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, temp, left, mid) + mergeSortAndCount(nums, temp, mid + 1, right);
        
        // Count reverse pairs during merging
        count += countReversePairs(nums, left, mid, right);
        
        // Merge the two halves
        merge(nums, temp, left, mid, right);
        
        return count;
    }
    
    // Count reverse pairs in the current segment
    int countReversePairs(std::vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        for (int i = left; i <= mid; ++i) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                ++j;
            }
            count += (j - mid - 1);
        }
        
        return count;
    }

    // Merge the two sorted halves
    void merge(std::vector<int>& nums, std::vector<int>& temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        
        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i];
        }
    }
};

```



Maximum Product Subarray
```cpp
int maxProduct(std::vector<int>& nums) {
    // Edge case: if the array is empty, return 0
    if (nums.empty()) {
        return 0;
    }
    
    // Initialize the first element as both the current max and min
    int currentMax = nums[0], currentMin = nums[0], maxProd = nums[0];
    
    // Iterate through the array from the second element
    for (size_t i = 1; i < nums.size(); ++i) {
        // If nums[i] is negative, we need to swap currentMax and currentMin
        // because a negative number may turn the smallest product into the largest
        if (nums[i] < 0) {
            std::swap(currentMax, currentMin);
        }
        
        // Update currentMax and currentMin based on the current number
        currentMax = std::max(nums[i], currentMax * nums[i]);
        currentMin = std::min(nums[i], currentMin * nums[i]);
        
        // Update maxProd with the largest product found so far
        maxProd = std::max(maxProd, currentMax);
    }
    
    return maxProd;
}


```






```cpp


```





```cpp


```




```cpp


```
