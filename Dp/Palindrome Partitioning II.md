***Problem:***
```
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.
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
#include <climits>
using namespace std;

class Solution {
public:
    int minCut(const string& s) {
        int n = (int)s.size();
        if (n <= 1) return 0;

        // Step 1: Precompute palindrome substrings with classic length-based DP
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;  // single chars are palindromes
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                isPalindrome[i][j] = (s[i] == s[j]) && (len == 2 || isPalindrome[i + 1][j - 1]);
            }
        }

        // Step 2: DP array to track min cuts needed for s[0..i]
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; ++i) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;  // whole substring s[0..i] is palindrome => no cuts needed
            } else {
                for (int j = 1; j <= i; ++j) {
                    if (isPalindrome[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
```


***Testcases:***
```
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

```
Input: s = "a"
Output: 0
```

```
Input: s = "ab"
Output: 1
```
