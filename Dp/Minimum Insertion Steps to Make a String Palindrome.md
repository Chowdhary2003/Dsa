***Problem:***
```
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
```



***Complexity:***
```
       Time Complexity: O(n^2)
       Space Complexity: O(n^2)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minInsertionsToMakePalindrome(const string& s) {
    int n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());

    // dp[i][j] = length of LCS of s[0..i-1] and rev[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == rev[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lpsLength = dp[n][n];
    return n - lpsLength; // minimum insertions = total length - LPS
}
```


***Testcases:***
```
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
```

```
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
```


```
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
```
