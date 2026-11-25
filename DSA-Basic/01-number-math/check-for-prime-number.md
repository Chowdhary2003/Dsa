# Check for Prime Number

## Problem
```
Given a number n, check whether it is a prime number or not.
Note: A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.
```



## Complexity
```
       Time Complexity: Worst-case:O(√n), Best-case: O(1)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <cmath>    // For std::sqrt
#include <cstdint>  // For int64_t
#include <iostream>

bool is_prime(int64_t n) {
    if (n <= 1) return false;
    if (n <= 3) return true;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check for factors using 6k ± 1 optimization
    for (int64_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
```


## Examples
```
Input: n = 7
Output: true
Explanation: 7 is a prime number because it is greater than 1 and has no divisors other than 1 and itself.
```

```
Input: n = 25
Output: false
Explanation: 25 is not a prime number because it is divisible by 5 (25 = 5 × 5), so it has divisors other than 1 and itself.
```

```
Input: n = 1
Output: false
Explanation: 1 has only one divisor (1 itself), which is not sufficient for it to be considered prime.
```
