
***Problem:***
```
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
```



***Complexity:***
```
       Time Complexity: O(log n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>

double pow(double x, int n) {
    // Edge case for 0 raised to a negative power (undefined)
    if (x == 0 && n < 0) {
        throw std::invalid_argument("0 cannot be raised to a negative power");
    }
    
    // Handle base case where n is 0
    if (n == 0) return 1;

    // Handle negative exponent by inverting the base
    long long N = n; // to handle edge case for INT_MIN
    if (n < 0) {
        x = 1 / x;
        N = -N; // Work with positive exponent for simplicity
    }

    double result = 1;
    while (N > 0) {
        if (N % 2 == 1) {
            result *= x; // If the exponent is odd, multiply by base
        }
        x *= x; // Square the base for the next power of 2
        N /= 2; // Halve the exponent
    }

    return result;
}

```


***Testcases:***
```
Input: x = 2.10000, n = 3
Output: 9.26100
```

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```
