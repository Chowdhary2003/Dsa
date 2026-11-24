***Problem :***
```
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.
```

***Complexity :***
```
Time Complexity: O(n ⋅ log(sum of elements)) 
Space Complexity: O(1)
```


***Code :***
```cpp
// Function to check if we can split the array into k subarrays with a maximum sum of 'maxSum'
bool canSplit(const vector<int>& nums, int k, int maxSum) {
    int subarrayCount = 1;  // We start with one subarray
    int currentSum = 0;

    for (int num : nums) {
        if (currentSum + num > maxSum) {
            // If adding this element exceeds maxSum, start a new subarray
            subarrayCount++;
            currentSum = num;  // Start new subarray with this element
            if (subarrayCount > k) {
                return false;  // If we need more than k subarrays, return false
            }
        } else {
            currentSum += num;  // Add to the current subarray
        }
    }
    return true;  // It's possible to split into k subarrays
}

// Main function to find the minimized largest sum
int splitArray(const vector<int>& nums, int k) {
    // The minimum possible largest sum is the maximum element, and the maximum is the sum of all elements
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;  // Avoid overflow

        if (canSplit(nums, k, mid)) {
            right = mid;  // Try to minimize the largest sum
        } else {
            left = mid + 1;  // Increase the sum
        }
    }
    return left;  // The minimized largest sum is found
}
```

***Testcases :***
```
Input: nums = [7,2,5,10,8], k = 2
Output: 18

Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
```

```
Input: nums = [1,2,3,4,5], k = 2
Output: 9

Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.`
```
