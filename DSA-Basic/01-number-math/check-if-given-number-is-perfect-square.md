# Check if given number is perfect square

## Problem
```
Given a number n, check if it is a perfect square or not. 
```



## Complexity
```
       Time Complexity: O(log n)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <iostream>
#include <limits> // For std::numeric_limits

bool isPerfectSquare(int n) {
    if (n < 0) return false; // Negative numbers can't be perfect squares
    
    if (n == 0 || n == 1) return true; // 0 and 1 are perfect squares
    
    int left = 1, right = n / 2; // No number greater than n/2 can be sqrt except for n=1 or 0 handled
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Use long long to prevent overflow in mid*mid
        long long square = static_cast<long long>(mid) * mid;
        
        if (square == n) {
            return true;
        } else if (square < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}
```


## Examples
```
Input  : n = 36
Output : Yes
```

```
Input : n = 2500
Output : Yes
Explanation: 2500 is a perfect square of 50
```

```
Input  : n = 8
Output : No
```
