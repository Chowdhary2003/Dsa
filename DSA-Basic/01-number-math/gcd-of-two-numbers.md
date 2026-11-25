# GCD of two numbers

## Problem
```
Given two positive integers a and b, the task is to find the GCD of the two numbers.
```



## Complexity
```
       Time Complexity: O(log min(a, b))
       Space Complexity: O(1), recursive - O(log min(a, b))
```



## Solution
```cpp
#include <iostream>
#include <cassert>

// Iterative Euclid's Algorithm for GCD
int gcd(int a, int b) {
    // Preconditions: a, b > 0
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

// Optional: Recursive version
/*
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
*/
```


## Examples
```
Input: a = 20, b = 28
Output: 4
Explanation: The factors of 20 are 1, 2, 4, 5, 10 and 20. The factors of 28 are 1, 2, 4, 7, 14 and 28. Among these factors, 1, 2 and 4 are the common factors of both 20 and 28. The greatest among the common factors is 4.
```

```
Input: a = 60, b = 36
Output: 12
Explanation: GCD of  60 and 36 is 12.
```
