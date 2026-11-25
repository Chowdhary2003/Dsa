# Find the Largest Number Among Three Numbers

## Problem
```
Given 3 integer numbers, the task is to find the largest number among them.
```



## Complexity
```
       Time Complexity: O(1)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <algorithm>  // for std::max
#include <iostream>

// Finds the largest among three integers
int largestOfThree(int a, int b, int c) {
    // Use std::max to find max between first two, then with the third
    return std::max({a, b, c});  // initializer_list overload of std::max in C++11+
}
```


## Examples
```
Input: a = 10, b = 22, c = 19
Output: 22 is the largest number.
Explanation: Among the numbers 5, 8, and 3, the largest number is 8.
```

```
Input: a = 12, b = 7, c = 9
Output: 12 is the largest number.
Explanation: Among the numbers 12, 7, and 9, the largest number is 12.
```
