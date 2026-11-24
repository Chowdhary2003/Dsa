***Problem:***
```
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
- For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.
```



***Complexity:***
```
       Time Complexity: O(m × n)
       Space Complexity: O(m × n), O(n) for space-optimized version
```



***Code:***
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    const size_t m = text1.size(), n = text2.size();

    // Create a DP table initialized to 0
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Fill the DP table
    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Match, extend LCS
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);  // No match, take the max
            }
        }
    }

    // The bottom-right cell contains the length of the LCS
    return dp[m][n];
}
```


***Code:***
```cpp
int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    const size_t m = text1.size(), n = text2.size();
    std::vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = std::max(prev[j], curr[j - 1]);
            }
        }
        std::swap(prev, curr);
    }

    return prev[n];
}
```



***Testcases:***
```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
```

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```
