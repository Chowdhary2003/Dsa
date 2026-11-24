***Problem:***
```
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    string longestPrefix(const string& s) {
        int n = s.size();
        vector<int> prefix(n, 0);  // prefix[i] = length of longest prefix-suffix for s[0..i]
        
        for (int i = 1; i < n; ++i) {
            int j = prefix[i - 1];  // length of previous best match
            
            // fall back until we find a match or j == 0
            while (j > 0 && s[i] != s[j]) {
                j = prefix[j - 1];
            }

            if (s[i] == s[j]) {
                ++j;
            }
            prefix[i] = j;
        }

        return s.substr(0, prefix[n - 1]);  // longest happy prefix
    }
};
```


***Testcases:***
```
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
```

```
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
```
