***Problem:***
```
Given an Integer n, find the reverse of its digits.
```



***Complexity:***
```
       Time Complexity: O(log₁₀(n))
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <limits>

int reverseInteger(int n) {
    int reversed = 0;

    while (n != 0) {
        int digit = n % 10;
        n /= 10;

        // Check for overflow before updating reversed
        if (reversed > (std::numeric_limits<int>::max() - digit) / 10)
            return 0;
        if (reversed < (std::numeric_limits<int>::min() - digit) / 10)
            return 0;

        reversed = reversed * 10 + digit;
    }

    return reversed;
}
```


***Testcases:***
```
Input: n = 122
Output: 221
Explanation: By reversing the digits of number, number will change into 221.
```

```
Input: n = 200
Output: 2
Explanation: By reversing the digits of number, number will change into 2.
```


---


***Problem***
```
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
```

***Complexity :***
```
Time Complexity: O(1) 
Space Complexity: O(1)
```


***Code :***
```cpp
int reverse(int x) {
    // Define the 32-bit signed integer range (if defined in limits.h ok (otherwise include))
    const int INT_MIN = -2147483648;
    const int INT_MAX = 2147483647;
    
    long reversed_x = 0;  // Use long to avoid overflow during reversal

    // Process the number digit by digit
    while (x != 0) {
        // Get the last digit
        int digit = x % 10;
        
        // Update the reversed number
        reversed_x = reversed_x * 10 + digit;

        // Check for overflow during the process
        if (reversed_x > INT_MAX || reversed_x < INT_MIN) {
            return 0;  // Return 0 if overflow occurs
        }

        // Remove the last digit from x
        x /= 10;
    }

    // Return the reversed number
    return (int)reversed_x;  // Cast back to int
}
```

<img width="850" alt="reverse-number-image1-Dvuaeusy" src="https://github.com/user-attachments/assets/0bc5d0a6-8605-4159-83f7-4e88db4714eb">

***Testcases :***
```
Input: x = 123
Output: 321
```
```
Input: x = -123
Output: -321
```
