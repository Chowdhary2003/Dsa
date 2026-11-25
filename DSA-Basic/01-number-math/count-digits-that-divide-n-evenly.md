# Count digits that divide n evenly

## Problem
```
Given a positive integer n,
count the number of digits in n that divide n evenly (i.e., without leaving a remainder).
Return the total number of such digits.
```

## Complexity
```
Time Complexity: O(log₁₀(n))
Space Complexity: O(1)
```


## Solution
```cpp
int countDividingDigits(int n) {
    int count = 0;
    int original = n;  // Store the original value of n for divisibility check

    // Process each digit of n
    while (n > 0) {
        int digit = n % 10;  // Get the last digit of n
        n /= 10;  // Remove the last digit

        // Skip division by zero and check divisibility
        if (digit != 0 && original % digit == 0) {
            count++;  // Increment count if the digit divides n evenly
        }
    }

    return count;
}
```

## Examples
```
Input: n = 12
Output: 2
Explanation: 1, 2 when both divide 12 leaves remainder 0.
```

```
Input: n = 23
Output: 0
Explanation: 2 and 3, none of them divide 23 evenly.
```
