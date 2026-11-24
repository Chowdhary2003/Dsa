***Problem:***
```
Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 10⁹ + 7.

A subsequence of a string is obtained by deleting zero or more characters from the string.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which aᵢ != bᵢ.
```



***Complexity:***
```
       Time Complexity: O(n³) worst-case
       Space Complexity: O(n²)
```



***Code:***
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        constexpr int MOD = 1'000'000'007;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: single characters
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        // Build up substrings from length 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int l = i + 1, r = j - 1;

                    // Find first and last occurrence of s[i] between (i+1, j-1)
                    while (l <= r && s[l] != s[i]) ++l;
                    while (l <= r && s[r] != s[i]) --r;

                    if (l > r) {
                        // No matching character inside
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 2) % MOD;
                    } else if (l == r) {
                        // One matching character
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 1) % MOD;
                    } else {
                        // More than one matching character
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % MOD - dp[l + 1][r - 1] + MOD) % MOD;
                    }
                } else {
                    dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % MOD - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }

        return dp[0][n - 1];
    }
};
```


***Testcases:***
```
Input: s = "bccb"
Output: 6
Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
```

```
Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
Output: 104860361
Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10⁹ + 7.
```
