***Problem:***
```
Given the number n (n >=0), find its factorial. Factorial of n is defined as 1 x 2 x ... x n. For n = 0, factorial is 1.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1), Recursive: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <cstdint>
#include <stdexcept>

// Iterative implementation
int64_t factorial_iterative(uint32_t n) {
    int64_t result = 1;
    for (uint32_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Recursive implementation
int64_t factorial_recursive(uint32_t n) {
    if (n == 0) return 1;
    return n * factorial_recursive(n - 1);
}
```


***Testcases:***
```
Input: n = 5
Output: 120
Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120
```

```
Input: n = 4
Output: 24
Explanation: 4! = 4 * 3 * 2 * 1 = 24
```
