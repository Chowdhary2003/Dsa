***Problem:***
```
Given a number, the task is to check if a number is divisible by 6 or not. The input number may be large and it may not be possible to store even if we use long long int.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <string>

bool isDivisibleBy6(const std::string& num) {
    if (num.empty()) return false;

    // Check if last digit is even (divisible by 2)
    char lastDigit = num.back();
    if ((lastDigit - '0') % 2 != 0) return false;

    // Calculate sum of digits mod 3
    int sumMod3 = 0;
    for (char digit : num) {
        if (digit < '0' || digit > '9') return false; // invalid character check
        sumMod3 = (sumMod3 + (digit - '0')) % 3;
    }

    return sumMod3 == 0;
}
```


***Testcases:***
```
Input  : n = 2112
Output: Yes
```

```
Input : n = 1124
Output : No
```

```
Input  : n = 363588395960667043875487
Output : No
```
