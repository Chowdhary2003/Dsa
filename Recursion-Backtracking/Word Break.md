
***Problem:***
```
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
```



***Complexity:***
```
       Time Complexity: O(N² * M)
       Space Complexity: O(N + M * K)
```



***Code:***
```cpp
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // dp[i] means s[0..i-1] can be segmented
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;  // empty string can be segmented trivially

        for (size_t i = 1; i <= s.length(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // Found a valid segmentation, no need to check more partitions
                }
            }
        }
        return dp[s.length()];
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
