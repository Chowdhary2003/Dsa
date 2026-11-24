***Problem:***
```
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
```



***Complexity:***
```
       Time Complexity: O(n + m)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <string>
#include <array>

class Solution {
public:
    bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
        // Since problem is about letters, use fixed size array for counts (assuming lowercase English)
        std::array<int, 26> letterCount{};
        
        // Count letters in magazine
        for (char ch : magazine) {
            ++letterCount[ch - 'a'];
        }

        // Check each letter in ransomNote, decrementing count, fail if insufficient
        for (char ch : ransomNote) {
            if (--letterCount[ch - 'a'] < 0) {
                return false; // Not enough letters
            }
        }
        return true;
    }
};
```


***Testcases:***
```
Input: ransomNote = "a", magazine = "b"
Output: false
```

```
Input: ransomNote = "aa", magazine = "ab"
Output: false
```

```
Input: ransomNote = "aa", magazine = "aab"
Output: true
```
