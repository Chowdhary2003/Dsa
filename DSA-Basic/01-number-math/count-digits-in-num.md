# Count digits in num

## Problem
```
 Given an integer N, return the number of digits in N.
```

## Complexity
```
Time Complexity: O(1) 
Space Complexity: O(1)
```


## Solution
```cpp
#include <cmath>  // For abs() and log10() functions

using namespace std;

// Function to count the digits in an integer
int countDigits(int n) {
    // Special case for zero as it has exactly 1 digit
    if (n == 0) return 1;

    // Use absolute value to handle negative numbers
    n = abs(n);

    // Efficient approach: Use log10 to calculate the number of digits
    return static_cast<int>(log10(n)) + 1;
}
```

## Examples
```
Input:N = 12345
Output:5
Explanation:  The number 12345 has 5 digits.
```
