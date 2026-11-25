# Armstrong's number or not

## Problem
```
Given a number x, determine whether the given number is Armstrong's number or not. A positive integer of n digits is called an Armstrong number of order n (order is the number of digits) if

abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + ....

Here a, b, c and d are digits of input number abcd.....
```



## Complexity
```
       Time Complexity: O(log² x)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <iostream>
#include <cmath>        // for std::log10, std::pow
#include <cstdint>      // for fixed-width integer types

bool isArmstrong(int x) {
    if (x < 0) return false; // Armstrong numbers are defined for non-negative integers

    int original = x;
    int n = x == 0 ? 1 : static_cast<int>(std::log10(x)) + 1; // number of digits

    int sum = 0;
    int temp = x;

    while (temp > 0) {
        int digit = temp % 10;

        // Use integer exponentiation to avoid precision errors
        int powered = 1;
        for (int i = 0; i < n; ++i) {
            powered *= digit;
        }

        sum += powered;
        temp /= 10;
    }

    return sum == original;
}
```


## Examples
```
Input: n = 153
Output: true
Explanation: 153 is an Armstrong number, 1*1*1 + 5*5*5 + 3*3*3 = 153
```

```
Input: n = 9474
Output: true
Explanation: 94 + 44 + 74 + 44 = 6561 + 256 + 2401 + 256 = 9474
```

```
Input: n = 123
Output: false
Explanation: 1³ + 2³ + 3³ = 1 + 8 + 27 = 36
```
