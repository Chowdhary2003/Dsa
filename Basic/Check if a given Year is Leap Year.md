***Problem:***
```
You are given an Integer n. Return true if It is a Leap Year otherwise return false. A leap year is a year that contains an additional day, February 29th, making it 366 days long instead of the usual 365 days. Leap years are necessary to keep our calendar in alignment with the Earth's revolutions around the Sun.

Note: A year is a leap year if "any one of " the following conditions are satisfied: 
1. The year is multiple of 400.
2. The year is a multiple of 4 and not a multiple of 100.
```



***Complexity:***
```
       Time Complexity: O(1)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>

bool isLeapYear(int year) {
    // Check if year is divisible by 400
    if (year % 400 == 0) {
        return true;
    }
    // If divisible by 100 but not by 400, it's not a leap year
    if (year % 100 == 0) {
        return false;
    }
    // If divisible by 4 but not by 100, it's a leap year
    if (year % 4 == 0) {
        return true;
    }
    // Otherwise, not a leap year
    return false;
}
```


***Testcases:***
```
Input: n = 4
Output: true
Explanation: 4 is not divisible by 100 and is divisible by 4 so its a leap year
```

```
Input: n = 2021
Output: false
Explanation: 2021 is not divisible by 100 and is also not divisible by 4 so its not a leap year
```
