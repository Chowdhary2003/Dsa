***Problem:***
```
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
```



***Complexity:***
```
       Time Complexity: O(log(min(m,n)))
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        // Ensure binary search is on the smaller array for O(log(min(m,n))) time
        const std::vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        const std::vector<int>& B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        int m = static_cast<int>(A.size());
        int n = static_cast<int>(B.size());
        int totalLeft = (m + n + 1) / 2; // Number of elements in left partition

        int left = 0;
        int right = m;

        while (left <= right) {
            int i = left + (right - left) / 2; // Partition index for A
            int j = totalLeft - i;             // Partition index for B

            // Handle edge cases with sentinel values
            int A_leftMax  = (i == 0) ? std::numeric_limits<int>::min() : A[i - 1];
            int A_rightMin = (i == m) ? std::numeric_limits<int>::max() : A[i];

            int B_leftMax  = (j == 0) ? std::numeric_limits<int>::min() : B[j - 1];
            int B_rightMin = (j == n) ? std::numeric_limits<int>::max() : B[j];

            // Check if partitions are correct
            if (A_leftMax <= B_rightMin && B_leftMax <= A_rightMin) {
                // Found correct partition; now compute median
                if ((m + n) % 2 == 1) {
                    // Odd length combined array: max of left side
                    return static_cast<double>(std::max(A_leftMax, B_leftMax));
                } else {
                    // Even length combined array: average of max left and min right
                    return (std::max(A_leftMax, B_leftMax) + std::min(A_rightMin, B_rightMin)) / 2.0;
                }
            } else if (A_leftMax > B_rightMin) {
                // Move partition left in A
                right = i - 1;
            } else {
                // Move partition right in A
                left = i + 1;
            }
        }

        // If input arrays are not sorted or invalid, no median can be found
        throw std::invalid_argument("Input arrays are not sorted or invalid.");
    }
};
```


***Testcases:***
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```
