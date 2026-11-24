***Problem:***
```
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n^2)
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <algorithm>

int longestPalindromeSubseq(const string& s) {
    int n = s.length();
    // DP table where dp[i][j] will store the length of longest palindromic subsequence in s[i..j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: every single character is a palindrome of length 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Build the DP table
    for (int len = 2; len <= n; ++len) { // length of the current substring
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; // j is the end index of the current substring
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2; // Include both s[i] and s[j]
            } else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]); // Exclude one character at a time
            }
        }
    }

    // The answer will be stored in dp[0][n-1]
    return dp[0][n - 1];
}
```


***Testcases:***
```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

```
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```
