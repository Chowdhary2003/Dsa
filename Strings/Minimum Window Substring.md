***Problem:***
```
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
```



***Complexity:***
```
       Time Complexity: O(m + n)
       Space Complexity: O(n + k)
```



***Code:***
```cpp
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
public:
    string minWindow(const string& s, const string& t) {
        if (t.empty() || s.empty() || t.size() > s.size()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = (int)need.size();
        int formed = 0;

        // window counts chars
        unordered_map<char, int> windowCounts;

        int left = 0, right = 0;
        int minLen = numeric_limits<int>::max();
        int minStart = 0;

        while (right < (int)s.size()) {
            char c = s[right];
            windowCounts[c]++;

            // Check if current char fulfills a needed frequency
            if (need.count(c) && windowCounts[c] == need[c]) {
                formed++;
            }

            // Try to contract the window until it stops being 'desirable'
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                windowCounts[leftChar]--;
                if (need.count(leftChar) && windowCounts[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return minLen == numeric_limits<int>::max() ? "" : s.substr(minStart, minLen);
    }
};
```


***Testcases:***
```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```
