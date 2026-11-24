# Find element in two merged arrays

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Return the k-th element in the combined ordering of two sorted arrays without explicitly merging them. The function returns -1 when k is outside the valid range.

## C++ Implementation

```cpp
int findKthElement(vector<int> arr1, vector<int> arr2, int k) {
    int m = arr1.size();
    int n = arr2.size();

    if (k < 1 || k > m + n) {
        // Handle out-of-bounds k.
        return -1;
    }

    int st1 = 0, st2 = 0;

    while (true) {
        if (st1 == m) {
            return arr2[st2 + k - 1];
        }
        if (st2 == n) {
            return arr1[st1 + k - 1];
        }
        if (k == 1) {
            return min(arr1[st1], arr2[st2]);
        }

        int mid1 = min(st1 + k / 2 - 1, m - 1);
        int mid2 = min(st2 + k / 2 - 1, n - 1);

        if (arr1[mid1] <= arr2[mid2]) {
            k -= mid1 - st1 + 1;
            st1 = mid1 + 1;
        } else {
            k -= mid2 - st2 + 1;
            st2 = mid2 + 1;
        }
    }
}
```
