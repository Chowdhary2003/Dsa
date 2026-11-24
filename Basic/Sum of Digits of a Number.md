***Problem:***
```
Given a number n, find the sum of its digits.
```



***Complexity:***
```
       Time Complexity: O(log₁₀ n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <cmath> // for std::abs

// Computes the sum of digits of an integer n
int sumOfDigits(int n) {
    n = std::abs(n); // Ensure non-negative
    int sum = 0;
    
    while (n > 0) {
        sum += n % 10; // Extract last digit
        n /= 10;       // Remove last digit
    }

    return sum;
}
```


***Testcases:***
```
Input: n = 687
Output: 21
Explanation: The sum of its digits are: 6 + 8 + 7 = 21
```

```
Input: n = 12
Output: 3
Explanation: The sum of its digits are: 1 + 2 = 3
```
