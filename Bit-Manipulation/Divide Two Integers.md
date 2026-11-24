***Problem:***
```
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.
```

> [!Note]
> Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.


***Complexity:***
```
       Time Complexity: O(log N)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <climits>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // overflow clamp
    }

    bool negative = (dividend < 0) ^ (divisor < 0);

    long long dividendL = std::llabs(static_cast<long long>(dividend));
    long long divisorL = std::llabs(static_cast<long long>(divisor));

    long long quotient = 0; // Use long long here

    while (dividendL >= divisorL) {
        long long temp = divisorL;
        long long multiple = 1;

        while (dividendL >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        dividendL -= temp;
        quotient += multiple;
    }

    if (negative) quotient = -quotient;

    // Clamp to int range explicitly
    if (quotient > INT_MAX) return INT_MAX;
    if (quotient < INT_MIN) return INT_MIN;

    return static_cast<int>(quotient);
}
```


***Testcases:***
```
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
```


```
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
```
