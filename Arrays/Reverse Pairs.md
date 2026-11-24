***Problem:***
```
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:
- 0 <= i < j < nums.length and
- nums[i] > 2 * nums[j].
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n), O(log n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        return mergeSortAndCount(nums, 0, int(nums.size()) - 1);
    }

private:
    int mergeSortAndCount(std::vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, left, mid) + mergeSortAndCount(nums, mid + 1, right);

        // Count reverse pairs between left and right sorted halves
        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (j <= right && static_cast<long long>(nums[i]) > 2LL * nums[j]) {
                ++j;
            }
            count += j - (mid + 1);
        }

        // Explicit merge to maintain sorted order
        std::vector<int> merged;
        merged.reserve(right - left + 1);

        int i = left, k = mid + 1;
        while (i <= mid && k <= right) {
            if (nums[i] <= nums[k]) merged.push_back(nums[i++]);
            else merged.push_back(nums[k++]);
        }
        while (i <= mid) merged.push_back(nums[i++]);
        while (k <= right) merged.push_back(nums[k++]);

        // Copy merged back to nums
        std::copy(merged.begin(), merged.end(), nums.begin() + left);

        return count;
    }
};
```


***Testcases:***
```
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
```

```
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
```
