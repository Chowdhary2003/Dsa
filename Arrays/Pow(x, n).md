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
#include <limits>

class Solution {
public:
    double myPow(double x, int n) {
        // Handle edge case: n == 0
        if (n == 0) return 1.0;

        // Handle INT_MIN to avoid overflow when negating
        long long N = n;  
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        double current_product = x;

        while (N > 0) {
            // If the current bit is set, multiply result by current_product
            if (N & 1) {
                result *= current_product;
            }
            current_product *= current_product; // Square the base for next bit
            N >>= 1; // Shift right to process next bit
        }
        return result;
    }
};
```


***Testcases:***
```
Input: x = 2.00000, n = 10
Output: 1024.00000
```

```
Input: x = 2.10000, n = 3
Output: 9.26100
```

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```
