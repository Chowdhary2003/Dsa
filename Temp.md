Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough






4Sum
```cpp
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Result to store the unique quadruplets
    vector<vector<int>> result;

    // Edge case: If there are less than 4 elements, return an empty result
    if (nums.size() < 4) return result;

    // Sort the input array to facilitate two-pointer approach
    sort(nums.begin(), nums.end());

    // Iterate through the array to find the first two elements of the quadruplet
    for (int i = 0; i < nums.size() - 3; ++i) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < nums.size() - 2; ++j) {
            // Skip duplicate values for the second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // Use two pointers to find the remaining two elements
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    // Found a valid quadruplet, add it to the result
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    
                    // Skip duplicates for the third element
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    // Skip duplicates for the fourth element
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    // Move both pointers after finding a valid quadruplet
                    ++left;
                    --right;
                }
                // If the sum is less than target, move the left pointer to the right to increase the sum
                else if (sum < target) {
                    ++left;
                }
                // If the sum is greater than target, move the right pointer to the left to decrease the sum
                else {
                    --right;
                }
            }
        }
    }

    return result;
}

```


Largest subarray with 0 sum
```cpp

int maxLen(const vector<int>& arr) {
    unordered_map<int, int> sum_map; // Maps cumulative sum to its first occurrence index
    int cumulative_sum = 0;
    int max_len = 0;

    for (int i = 0; i < arr.size(); ++i) {
        cumulative_sum += arr[i];

        // If the cumulative sum is 0, the subarray from index 0 to i has a sum of 0
        if (cumulative_sum == 0) {
            max_len = i + 1;
        }

        // If cumulative_sum was already encountered, we have a subarray with sum 0
        if (sum_map.find(cumulative_sum) != sum_map.end()) {
            max_len = max(max_len, i - sum_map[cumulative_sum]);
        } else {
            // Store the index of the first occurrence of the cumulative_sum
            sum_map[cumulative_sum] = i;
        }
    }

    return max_len;
}

```





	
Count number of subarrays with given xor K
```cpp
int countSubarraysWithXor(const vector<int>& A, int B) {
    // HashMap to store the frequency of prefix XOR values
    unordered_map<int, int> prefixXorCount;
    
    // Initialize with prefix XOR 0 (to handle cases where a subarray itself equals B)
    prefixXorCount[0] = 1;
    
    int currentXor = 0;  // This will store the running XOR of the array
    int result = 0;      // This will store the number of subarrays with XOR B
    
    // Iterate over the array
    for (int num : A) {
        currentXor ^= num;  // Update running XOR
        
        // Check how many times (currentXor ^ B) has appeared before
        if (prefixXorCount.find(currentXor ^ B) != prefixXorCount.end()) {
            result += prefixXorCount[currentXor ^ B];
        }
        
        // Update the count of the current prefix XOR in the map
        prefixXorCount[currentXor]++;
    }
    
    return result;
}

```




Merge Intervals

```cpp

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Edge case: if there are no intervals, return an empty list
    if (intervals.empty()) return {};

    // Step 1: Sort intervals by the starting value
    sort(intervals.begin(), intervals.end());

    // Step 2: Initialize a result vector to store the merged intervals
    vector<vector<int>> merged;

    // Step 3: Iterate through the sorted intervals
    for (const auto& interval : intervals) {
        // If merged is empty or there's no overlap, add the current interval
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            // If there's an overlap, merge the intervals by updating the end
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}
```


Merge Sorted Array
```cpp

void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) {
    // Start from the end of nums1 and nums2
    int p1 = m - 1; // Pointer for the last element in nums1
    int p2 = n - 1; // Pointer for the last element in nums2
    int p = m + n - 1; // Pointer for the last position in nums1

    // Merge nums2 into nums1 starting from the back
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            --p1;
        } else {
            nums1[p] = nums2[p2];
            --p2;
        }
        --p;
    }

    // If there are any remaining elements in nums2, copy them
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        --p2;
        --p;
    }
}
```


Missing And Repeating

```cpp

std::pair<int, int> findMissingAndDuplicate(const std::vector<int>& arr) {
    int n = arr.size();
    
    // Initialize sum and sum of squares for both expected and actual values
    long long expectedSum = (n * (n + 1)) / 2;
    long long expectedSumSq = (n * (n + 1) * (2 * n + 1)) / 6;
    
    long long actualSum = 0;
    long long actualSumSq = 0;
    
    // Calculate actual sum and sum of squares from the array
    for (int num : arr) {
        actualSum += num;
        actualSumSq += (long long)num * num;
    }

    // The difference in sums
    long long diffSum = expectedSum - actualSum;  // a - b
    long long diffSumSq = expectedSumSq - actualSumSq;  // a^2 - b^2
    
    // Solve for a + b using the identity a^2 - b^2 = (a - b)(a + b)
    long long sumAB = diffSumSq / diffSum;  // (a + b)
    
    // Now solve for a and b
    int a = (diffSum + sumAB) / 2;
    int b = a - diffSum;
    
    return {a, b};
}
```


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
