***Problem:***
```
Ninja is now bored with numbers and is now playing with characters but hates when he gets repeated characters. Ninja is provided a string, and he wants to return the first unique character in the string.The string will contain characters only from the English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). If there is no non-repeating character, print the first character of the string. If there is no non-repeating character, return the first character of the string.
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
#include <unordered_map>

// Function to find the first unique character
char firstUniqueChar(const string& s) {
    if (s.empty()) return '\0';  // Assuming empty string returns null char

    unordered_map<char, int> freq;

    // First pass: count frequency of each character
    for (char c : s) {
        ++freq[c];
    }

    // Second pass: find first character with frequency 1
    for (char c : s) {
        if (freq[c] == 1) {
            return c;
        }
    }

    // No unique character found: return first character as fallback
    return s[0];
}
```


***Testcases:***
```
Sample Input 1 :
aDcadhc
AabBcC
Sample Output 1:
 D
 A
Explanation for Sample Input 1:
In the first test case, ‘a’ is repeated.’ D’ is the first non-repeating character in the string, so we return it.

In the second test case, all the characters are non-repeating, so we return the first character.
```

```
Sample Input 2 :
 ABcd
 AAAbcdb
Sample Output 2:
 A
 c 
```
