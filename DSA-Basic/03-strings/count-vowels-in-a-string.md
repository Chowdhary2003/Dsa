# Count vowels in a string

## Problem
```
Given a string, count the total number of vowels (a, e, i, o, u) in it. There are two methods to count total number of vowels in a string.
1. Iterative 
2. Recursive
```



## Complexity
```
       Time Complexity: O(n)
       Space Complexity: O(1), Recursive: O(n)
```



## Solution
```cpp
#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

// Utility: Check if a character is a vowel (case-insensitive)
inline bool isVowel(char ch) {
    static const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.count(std::tolower(static_cast<unsigned char>(ch))) > 0;
}

// Iterative solution
int countVowelsIterative(const std::string& s) {
    int count = 0;
    for (char ch : s) {
        if (isVowel(ch)) {
            ++count;
        }
    }
    return count;
}

// Recursive solution helper
int countVowelsRecursiveHelper(const std::string& s, size_t index) {
    if (index == s.size()) {
        return 0; // base case: end of string
    }
    return (isVowel(s[index]) ? 1 : 0) + countVowelsRecursiveHelper(s, index + 1);
}

// Recursive interface
int countVowelsRecursive(const std::string& s) {
    return countVowelsRecursiveHelper(s, 0);
}
```


## Examples
```
Input : abc de
Output : 2
```

```
Input : geeksforgeeks portal
Output : 7
```
