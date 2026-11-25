***Problem:***
```
Given an integer n, find the absolute difference between sum of the squares of first n natural numbers and square of sum of first n natural numbers.
```



***Complexity:***
```
       Time Complexity: O(1)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <cmath>        // For std::abs
#include <cstdint>      // For fixed-width int types

// Use int64_t for safe arithmetic (especially for large n)
int64_t differenceOfSums(int64_t n) {
    // Sum of first n natural numbers
    int64_t sum = n * (n + 1) / 2;

    // Sum of squares of first n natural numbers
    int64_t sumOfSquares = n * (n + 1) * (2 * n + 1) / 6;

    // Return the absolute difference
    return std::abs(sumOfSquares - sum * sum);
}
```


***Testcases:***
```
Input : n = 3
Output : 22
Sum of first three numbers is 3 + 2 + 1 = 6
Square of the sum =  36
Sum of squares of first three is 9 + 4 + 1 = 14
Absolute difference = 36 - 14 = 22
```

```
Input : n = 10
Output : 2640
```
