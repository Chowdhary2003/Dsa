***Problem:***
```
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <array>
#include <string>

bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;

    std::array<int, 256> freq{};  // zero-initialized

    for (std::size_t i = 0; i < s.size(); ++i) {
        ++freq[static_cast<unsigned char>(s[i])];
        --freq[static_cast<unsigned char>(t[i])];
    }

    // All frequencies must return to zero
    for (int count : freq) {
        if (count != 0) return false;
    }

    return true;
}
```


***Testcases:***
```
Input: s = "anagram", t = "nagaram"
Output: true
```

```
Input: s = "rat", t = "car"
Output: false
```
