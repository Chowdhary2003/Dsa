***Problem:***
```
Given two variables a and y, swap two variables without using a third variable. 
```



***Complexity:***
```
       Time Complexity: O(1)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <type_traits>  // for std::is_integral_v

// Swaps two integral variables using XOR without extra storage.
// Requires: a and y must be integral types.
template<typename T>
void swap_no_temp(T& a, T& y) {
    static_assert(std::is_integral_v<T>, "swap_no_temp requires integral types.");

    if (&a == &y) return;  // No need to swap if both references are the same.

    a ^= y;
    y ^= a;
    a ^= y;
}
```


***Testcases:***
```
Input: a = 2, b = 3
Output: a = 3, b = 2
```

```
Input: a = 10, b = 10
Output: a = 10, b = 10
```
