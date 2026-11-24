***Problem:***
```
Given a string s, you have to find the number of palindromic subsequences (need not necessarily be distinct) present in the string s. 
```



***Complexity:***
```
       Time Complexity: O(n²)
       Space Complexity: O(n²)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(const string& s) {
        const int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Every single character is a palindrome
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // Expand for substrings of length 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
            }
        }

        return dp[0][n - 1];
    }
};
```


***Testcases:***
```
Input: s = "abcd"
Output: 4
Explanation: palindromic subsequence are : 'a' ,'b', 'c' ,'d'
```

```
Input: s = "aab"
Output: 4
Explanation: palindromic subsequence are : 'a', 'a', 'b', 'aa'
```

```
Input: s = "b"
Output: 1
Explanation: palindromic subsequence are : 'b'
```
