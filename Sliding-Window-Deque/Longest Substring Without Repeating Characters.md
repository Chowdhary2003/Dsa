***Problem:***
```
Given a string s, find the length of the longest substring without duplicate characters.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(min(n, k))
```



***Code:***
```cpp
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastSeen;
    int maxLength = 0;
    int left = 0; // Left end of the sliding window

    for (int right = 0; right < s.size(); ++right) {
        char c = s[right];
        
        // If the character was seen and is inside the current window
        if (lastSeen.count(c) && lastSeen[c] >= left) {
            left = lastSeen[c] + 1; // Move left past the previous occurrence
        }
        
        lastSeen[c] = right; // Update last seen index of current character
        maxLength = max(maxLength, right - left + 1); // Update max length
    }
    
    return maxLength;
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
