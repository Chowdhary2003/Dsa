***Problem:***
```
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
```



***Complexity:***
```
       Time Complexity: O(m * n)
       Space Complexity: O(m * n)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the shortest common supersequence
string shortestCommonSupersequence(const string& str1, const string& str2) {
    int m = str1.size(), n = str2.size();
    // DP table for LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    // Reconstruct SCS using the DP table
    string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result.push_back(str1[i - 1]);
            --i; --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            result.push_back(str1[i - 1]);
            --i;
        } else {
            result.push_back(str2[j - 1]);
            --j;
        }
    }

    // Add remaining characters
    while (i > 0) result.push_back(str1[--i]);
    while (j > 0) result.push_back(str2[--j]);

    // Reverse the result since we built it backwards
    reverse(result.begin(), result.end());
    return result;
}
```


***Testcases:***
```
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
```

```
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
```
