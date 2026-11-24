***Problem:***
```
Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.
```



***Complexity:***
```
       Time Complexity: O(log(min(m, n)))
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

int findKthElement(const std::vector<int>& a, const std::vector<int>& b, int k) {
    int m = a.size();
    int n = b.size();

    // Ensure a is the smaller array for binary search efficiency
    if (m > n) return findKthElement(b, a, k);

    // Edge cases: one array empty
    if (m == 0) return b[k - 1];
    if (k == 1) return std::min(a[0], b[0]);

    // Define search boundaries for elements taken from a
    int left = std::max(0, k - n);
    int right = std::min(k, m);

    while (left <= right) {
        int i = left + (right - left) / 2;
        int j = k - i;

        int aLeft = (i == 0) ? std::numeric_limits<int>::min() : a[i - 1];
        int aRight = (i == m) ? std::numeric_limits<int>::max() : a[i];
        int bLeft = (j == 0) ? std::numeric_limits<int>::min() : b[j - 1];
        int bRight = (j == n) ? std::numeric_limits<int>::max() : b[j];

        // Check if partition is correct
        if (aLeft <= bRight && bLeft <= aRight) {
            // kth element is max of left parts
            return std::max(aLeft, bLeft);
        } else if (aLeft > bRight) {
            // Too many elements taken from a, decrease i
            right = i - 1;
        } else {
            // Too few elements taken from a, increase i
            left = i + 1;
        }
    }

    // Should never reach here if inputs are valid
    throw std::invalid_argument("Invalid inputs or k out of range");
}
```


***Testcases:***
```
Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5

Output: 6

Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
```

```
Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7

Output: 256

Explanation: Final sorted array is - [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892], 7th element of this array is 256.
```
