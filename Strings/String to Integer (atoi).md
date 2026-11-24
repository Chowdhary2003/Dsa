***Problem:***
```
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:
1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

Return the integer as the final result.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(const string& s) {
        int i = 0, n = s.size();
        // 1️⃣ Skip leading whitespace
        while (i < n && isspace(s[i])) ++i;
        if (i == n) return 0;

        // 2️⃣ Determine sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // 3️⃣ Parse digits and check overflow
        long result = 0; // Use long to detect overflow safely
        const int INT_MAX_VAL = numeric_limits<int>::max();
        const int INT_MIN_VAL = numeric_limits<int>::min();

        while (i < n && isdigit(s[i])) {
            int digit = s[i++] - '0';

            // Overflow detection
            if (result > (INT_MAX_VAL - digit) / 10) {
                return (sign == 1) ? INT_MAX_VAL : INT_MIN_VAL;
            }
            result = result * 10 + digit;
        }

        return static_cast<int>(result * sign);
    }
};
```


***Testcases:***
```
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
```

```
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
```

```
Input: s = "1337c0d3"
Output: 1337
Explanation:
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
```

```
Input: s = "0-1"
Output: 0
Explanation:
Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
```


```
Input: s = "words and 987"
Output: 0
Explanation:
Reading stops at the first non-digit character 'w'.
```
