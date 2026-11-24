***Problem:***
```
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
```



***Complexity:***
```
       Time Complexity: O(n + m)
       Space Complexity: O(m)
```



***Code:***
```cpp
#include <bits/stdc++.h>
using namespace std;

// KMP-based solution
class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        if (needle.empty()) return 0;
        if (needle.size() > haystack.size()) return -1;

        // Build LPS (Longest Prefix-Suffix) array
        vector<int> lps = buildLPS(needle);

        int i = 0; // index in haystack
        int j = 0; // index in needle

        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++; 
                j++;
                if (j == needle.size()) {
                    return i - j; // full match found
                }
            } else {
                if (j > 0) {
                    j = lps[j - 1];  // fallback in the pattern
                } else {
                    i++; // advance haystack if no partial match
                }
            }
        }
        return -1;
    }

private:
    // Build LPS array: lps[i] = length of longest prefix that is also suffix for needle[0..i]
    vector<int> buildLPS(const string& pat) {
        vector<int> lps(pat.size(), 0);
        int len = 0; // length of current longest prefix-suffix
        int i = 1;

        while (i < pat.size()) {
            if (pat[i] == pat[len]) {
                lps[i] = ++len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];  // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};
```


***Testcases:***
```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```
