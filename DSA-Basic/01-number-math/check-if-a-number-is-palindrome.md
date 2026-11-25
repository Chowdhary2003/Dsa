# Check if a number is Palindrome

## Problem
```
Given an integer n, find whether the number is Palindrome or not. A number is a Palindrome if it remains the same when its digits are reversed.
```



## Complexity
```
       Time Complexity: O(log₁₀ n)
       Space Complexity: O(1)
```



## Solution
```cpp
#include <iostream>

class Solution {
public:
    bool isPalindrome(int n) {
        // Negative numbers and numbers ending with 0 (except 0 itself) are not palindrome
        if (n < 0 || (n % 10 == 0 && n != 0)) return false;

        int reversedHalf = 0;
        while (n > reversedHalf) {
            reversedHalf = reversedHalf * 10 + n % 10;
            n /= 10;
        }

        // For even length, both halves should be equal.
        // For odd length, reversedHalf/10 removes the middle digit.
        return n == reversedHalf || n == reversedHalf / 10;
    }
};
```


## Examples
```
Input: n = 12321
Output: Yes
Explanation: 12321 is a Palindrome number because after reversing its digits, the number becomes 12321 which is the same as the original number.
```

```
Input: n = 1234
Output: No
Explanation: 1234 is not a Palindrome number because after reversing its digits, the number becomes 4321 which is different from the original number.
```
