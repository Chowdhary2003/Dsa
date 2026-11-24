***Problem:***
```
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:
Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.

Return the integer as the final result.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp

#include <string>
#include <climits>

int myAtoi(const std::string& s) {
    int i = 0;
    int n = s.length();
    
    // Skip leading whitespace
    while (i < n && std::isspace(s[i])) {
        ++i;
    }

    // Handle sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        ++i;
    }

    // Convert digits
    long result = 0;  // Use long to detect overflow before assigning to int
    while (i < n && std::isdigit(s[i])) {
        int digit = s[i++] - '0';

        // Check for overflow
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
    }

    return static_cast<int>(sign * result);
}

```


***Testcases:***
```
Input: s = " -042"

Output: -42

Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
          ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
```

```
Input: s = "words and 987"

Output: 0

Explanation:
Reading stops at the first non-digit character 'w'.
```
