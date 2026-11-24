***Problem:***
```
Given a string s, return the longest palindromic substring in s.
```



***Complexity:***
```
       Time Complexity: O(n²)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(const string& s) {
        const int n = s.size();
        if (n < 2) return s; // trivial case

        int start = 0, maxLen = 1;

        // Pure lambda that computes palindrome bounds
        auto expand = [&](int left, int right) -> pair<int, int> {
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            int len = right - left - 1;
            return {left + 1, len};
        };

        for (int i = 0; i < n; ++i) {
            // Odd-length palindrome
            auto [oddStart, oddLen] = expand(i, i);
            if (oddLen > maxLen) { start = oddStart; maxLen = oddLen; }

            // Even-length palindrome
            auto [evenStart, evenLen] = expand(i, i + 1);
            if (evenLen > maxLen) { start = evenStart; maxLen = evenLen; }
        }

        return s.substr(start, maxLen);
    }
};
```


***Testcases:***
```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

```
Input: s = "cbbd"
Output: "bb"
```
