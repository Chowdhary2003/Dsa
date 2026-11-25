# Compute average of two numbers without overflow

## Problem
```
Given two numbers A and B, such that 0 <= A <= B <= (231 - 1). Compute the average ((A + B) / 2) of the two numbers.
```



## Complexity
```
       Time Complexity: O(1)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <iostream>
#include <cstdint>
#include <cassert>

// Safely compute the average of two non-negative integers
int average(int A, int B) {
    assert(0 <= A && A <= B && B <= INT32_MAX); // Defensive programming
    return A + (B - A) / 2;
}
```


## Examples
```
Input: A = 1000000000, B = 2000000000
Output: 1500000000.000000
Explanation: (A + B)/2 = (1000000000+ 2000000000)/2 = 1500000000.000000
```

```
Input: A = 2000000000, B = 2000000001
Output: 2000000000.500000
Explanation: (A + B)/2 = (2000000000 + 2000000001)/2 = 2000000000.500000
```
