***Problem:***
```
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
```



***Complexity:***
```
       Time Complexity: O(n² * k)
       Space Complexity: O(n) for DP array + O(m * k) for dictionary storage
```



***Code:***
```cpp
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        int n = static_cast<int>(s.size());
        std::vector<bool> dp(n + 1, false);
        dp[0] = true; // base case: empty string

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // early stop once dp[i] is true
                }
            }
        }
        return dp[n];
    }
};
```


***Testcases:***
```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
```

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```
