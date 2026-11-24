***Problem:***
```
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
```



***Complexity:***
```
       Time Complexity: O(m + n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) {
    int i = m - 1;          // Pointer to last valid element in nums1
    int j = n - 1;          // Pointer to last element in nums2
    int k = m + n - 1;      // Pointer to position to fill in nums1 (from end)

    // Merge backwards while nums2 still has elements
    while (j >= 0) {
        // If nums1 has elements left and nums1[i] is greater than nums2[j],
        // place nums1[i] at the current position k, then decrement i and k.
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            // Otherwise, place nums2[j] at position k, then decrement j and k.
            nums1[k--] = nums2[j--];
        }
    }
}
```


***Testcases:***
```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```

```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
```


```
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
```
