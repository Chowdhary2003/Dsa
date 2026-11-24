***Problem:***
```
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

- '.' Matches any single character.​​​​
- '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).
```



***Complexity:***
```
       Time Complexity: O(m * n)
       Space Complexity: O(m * n)
```



***Code:***
```cpp
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        int m = (int)s.size();
        int n = (int)p.size();
        // dp[i][j] = whether s[i:] matches p[j:]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        dp[m][n] = true;  // empty string matches empty pattern

        // Fill dp from the end towards start
        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                bool firstMatch = (i < m) && (p[j] == s[i] || p[j] == '.');

                if (j + 1 < n && p[j + 1] == '*') {
                    // '*' can mean zero occurrence or more occurrences if first matches
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                } else {
                    // no '*' follows, so must match first char and rest
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
```


***Testcases:***
```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```
