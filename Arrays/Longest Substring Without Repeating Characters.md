***Problem:***
```
Given a string s, find the length of the longest substring without duplicate characters.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: (min(m, n))
```



***Code:***
```cpp
#include <string>
#include <unordered_map>
#include <algorithm>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> lastIndex; // char -> last seen index
    int maxLen = 0;
    int left = 0; // window start


    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        char c = s[right];
        // Use iterator find to avoid double lookup
        if (auto it = lastIndex.find(c); it != lastIndex.end() && it->second >= left) {
            left = it->second + 1;
        }
        lastIndex[c] = right; // update last seen index
        maxLen = std::max(maxLen, right - left + 1);
    }
    return maxLen;
}
```


***Testcases:***
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```
