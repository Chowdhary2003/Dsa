***Problem:***
```
Given a string s, find the length of the longest substring without duplicate characters.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(min(m, n)) where m = charset size (e.g., 128 for ASCII)
```



***Code:***
```cpp
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_map<char, int> charIndex; // char -> last index
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            char c = s[right];
            // If char seen before and inside current window, move left pointer
            if (charIndex.contains(c) && charIndex[c] >= left) {
                left = charIndex[c] + 1;
            }
            charIndex[c] = right;
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
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
