# Check whether a given number is even or odd

## Problem
```
Given a number n, check whether it is even or odd. Return true for even and false for odd.
```



## Complexity
```
       Time Complexity: O(1)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <iostream>

// Returns true if n is even, false if odd
constexpr bool isEven(int n) noexcept {
    return (n & 1) == 0;
}
```


## Examples
```
Input: n = 15
Output: false
Explanation: 15 % 2 = 1, so 15 is odd .
```

```
Input: n = 44
Output: true
Explanation: 44 % 2 = 0, so 44 is even.
```
