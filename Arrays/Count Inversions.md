***Problem:***
```
Given an integer array nums. Return the number of inversions in the array.

Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
- It indicates how close an array is to being sorted.
- A sorted array has an inversion count of 0.
- An array sorted in descending order has maximum inversion.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n) + O(log n)
```



***Code:***
```cpp
#include <vector>

class InversionCounter {
public:
    // Public API to count inversions in the input vector
    long long countInversions(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        temp_.resize(nums.size());
        return mergeSort(nums, 0, static_cast<int>(nums.size()) - 1);
    }

private:
    std::vector<int> temp_;

    // Recursive merge sort that returns inversion count in nums[left..right]
    long long mergeSort(std::vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        long long invCount = 0;

        invCount += mergeSort(nums, left, mid);
        invCount += mergeSort(nums, mid + 1, right);
        invCount += merge(nums, left, mid, right);

        return invCount;
    }

    // Merge two sorted halves and count inversions where left element > right element
    long long merge(std::vector<int>& nums, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        long long invCount = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp_[k++] = nums[i++];
            } else {
                // nums[i] > nums[j] and i < j, so all elements from i to mid form inversions with nums[j]
                invCount += static_cast<long long>(mid - i + 1);
                temp_[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp_[k++] = nums[i++];
        }

        while (j <= right) {
            temp_[k++] = nums[j++];
        }

        // Copy back merged elements to original vector
        for (int idx = left; idx <= right; ++idx) {
            nums[idx] = temp_[idx];
        }

        return invCount;
    }
};
```


***Testcases:***
```
Input: nums = [2, 3, 7, 1, 3, 5]
Output: 5
Explanation: The responsible indexes are:
nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5
```

```
Input: nums = [-10, -5, 6, 11, 15, 17]
Output: 0
Explanation: nums is sorted, hence no inversions present.
```
