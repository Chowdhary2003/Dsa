***Problem:***
```
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
```



***Complexity:***
```
       Time Complexity: O(m + n)
       Space Complexity: O(k)
```



***Code:***
```cpp
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty() || t.size() > s.size()) return "";

    unordered_map<char, int> targetFreq;
    for (char c : t) targetFreq[c]++;

    unordered_map<char, int> windowFreq;
    int required = targetFreq.size();
    int formed = 0;
    
    int left = 0, right = 0;
    int minLen = INT_MAX;
    int startIdx = 0;

    while (right < s.size()) {
        char c = s[right];
        windowFreq[c]++;
        
        if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }

            char leftChar = s[left];
            windowFreq[leftChar]--;
            if (targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar]) {
                formed--;
            }
            left++;
        }

        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
}
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
