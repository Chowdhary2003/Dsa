***Problem:***
```
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;

        // Build KMP table (LPS: Longest Prefix Suffix)
        int n = combined.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                ++len;
            }
            lps[i] = len;
        }

        int palindrome_len = lps.back();
        string suffix = s.substr(palindrome_len);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};
```


***Testcases:***
```
Input: s = "aacecaaa"
Output: "aaacecaaa"
```

```
Input: s = "abcd"
Output: "dcbabcd"
```
