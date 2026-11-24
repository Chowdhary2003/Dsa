***Problem:***
```
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".
```



***Complexity:***
```
       Time Complexity: O(m + n), O((m + n) * m) [worst-case]
       Space Complexity: O(m + n)
```



***Code:***
```cpp
#include <iostream>
#include <string>
#include <cmath>

int repeatedStringMatch(const string& a, const string& b) {
    string repeated;
    repeated.reserve(b.size() + a.size());  // Optimize reallocations

    int count = 0;
    // Repeat until repeated.length >= b.length
    while (repeated.length() < b.length()) {
        repeated += a;
        ++count;
    }
    
    // Check if b is a substring at current or next repetition
    if (repeated.find(b) != string::npos) return count;

    repeated += a;
    if (repeated.find(b) != string::npos) return count + 1;

    return -1; // Impossible to form b as a substring
}
```


***Testcases:***
```
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
```

```
Input: a = "a", b = "aa"
Output: 2
```
