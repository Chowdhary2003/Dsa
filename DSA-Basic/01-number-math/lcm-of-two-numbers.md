# LCM of two numbers

## Problem
```
Given two positive integers a and b. Find the Least Common Multiple (LCM) of a and b.
LCM of two numbers is the smallest number which can be divided by both numbers. 
```



## Complexity
```
       Time Complexity: O(log min(a,b))
       Space Complexity: O(1)
```



## Solution
```cpp
#include <iostream>
#include <numeric>  // For std::gcd (C++17)

long long lcm(long long a, long long b) {
    // Using 64-bit to reduce overflow risk for large inputs
    long long gcd = std::gcd(a, b);
    // Divide before multiply to avoid overflow
    return (a / gcd) * b;
}
```


## Examples
```
Input :  a = 10, b = 5
Output :  10
Explanation : 10 is the smallest number divisible by both 10 and 5
```

```
Input :  a = 5, b = 11
Output :  55
Explanation : 55 is the smallest number divisible by both 5 and 11
```
