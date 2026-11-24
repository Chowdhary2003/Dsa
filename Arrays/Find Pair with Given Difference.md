***Problem:***
```
Given an array, arr[] and an integer x, return true if there exists a pair of elements in the array whose absolute difference is x, otherwise, return false.
```



***Complexity:***
```
       Time Complexity: Worst-case: O(n), Best-case (early exit): O(1)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

bool hasPairWithDifference(const std::vector<int>& arr, int x) {
    if (x < 0) return false; // absolute difference can't be negative

    if (x == 0) {
        // Need duplicates
        std::unordered_map<int, int> freq;
        for (int num : arr) {
            if (++freq[num] > 1) return true;
        }
        return false;
    }

    std::unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(num + x) || seen.count(num - x)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}
```


***Testcases:***
```
Input: arr[] = [5, 20, 3, 2, 5, 80], x = 78
Output: true
Explanation: Pair (2, 80) have an absolute difference of 78.
```

```
Input: arr[] = [90, 70, 20, 80, 50], x = 45
Output: false
Explanation: There is no pair with absolute difference of 45.
```

```
Input: arr[] = [1], x = 1
Output: false
```
