# Count Odd and Even

## Problem
```
Given an array arr[] of positive integers. The task is to return the count of the number of odd and even elements in the array.

Note: Return two elements where the first one in the count of odd & second one is the count of even.
```



## Complexity
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <vector>
#include <utility> // for std::pair

std::pair<int, int> countOddEven(const std::vector<int>& arr) {
    int oddCount = 0;
    int evenCount = 0;

    for (int num : arr) {
        if (num % 2 == 0) {
            ++evenCount;
        } else {
            ++oddCount;
        }
    }

    return {oddCount, evenCount}; // structured binding supported from C++17
}
```


## Examples
```
Input: arr[] = [1, 2, 3, 4, 5]
Output: 3 2
Explanation: There are 3 odd elements (1, 3, 5) and 2 even elements (2 and 4).
```

```
Input: arr[] = [1, 1]
Output: 2 0
Explanation: There are 2 odd elements (1, 1) and no even elements.
```
