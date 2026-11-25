# LCM And GCD

## Problem
```
Given two integers a and b, Your task is to return a list containing their LCM and GCD.
```

## Complexity
```
Time Complexity: O(log(min(a, b))) 
Space Complexity: O(1)
```


## Solution
```cpp
// Function to compute the GCD using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;  // Replace a with the remainder of a divided by b
        std::swap(a, b);  // Swap a and b
    }
    return a;  // When b becomes 0, a is the GCD
}
// Function to compute the LCM using the relationship between GCD and LCM
int lcm(int a, int b) {
    return std::abs(a * b) / gcd(a, b);  // abs() to handle negative numbers
}
vector<int> calculateLCMAndGCD(int a, int b) {
    int gcd_result = gcd(a, b);  // Calculate GCD
    int lcm_result = lcm(a, b);  // Calculate LCM
    return {lcm_result, gcd_result};  // Return both as a list
}

```

## Examples
```
Input: a = 5 , b = 10
Output: [10, 5]
Explanation: LCM of 5 and 10 is 10, while their GCD is 5.
```

```
Input: a = 14 , b = 8
Output: [56, 2]
Explanation: LCM of 14 and 8 is 56, while their GCD is 2.
```
