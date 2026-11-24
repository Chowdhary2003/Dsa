***Problem:***
```
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.
```



***Complexity:***
```
       Time Complexity: O(m * n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <limits>

int numDistinct(const string& s, const string& t) {
    int m = s.size(), n = t.size();
    if (n > m) return 0;

    vector<uint64_t> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= 1; --j) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
                if (dp[j] > numeric_limits<int>::max()) {
                    // Fail fast or cap if necessary
                    // You can log or handle it if allowed
                }
            }
        }
    }

    return static_cast<int>(dp[n]);  // Safe conversion
}
```


***Testcases:***

![Screenshot 2025-05-21 182456](https://github.com/user-attachments/assets/9c04a906-ac07-4d15-b9a2-982cda2e0a53)
