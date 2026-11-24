***Problem:***
```
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <string>
#include <vector>
#include <algorithm>

int characterReplacement(const string& s, int k) {
    vector<int> freq(26, 0);  // frequency of letters A-Z
    int left = 0;
    int maxFreq = 0;
    int result = 0;

    for (int right = 0; right < s.size(); ++right) {
        int idx = s[right] - 'A';
        freq[idx]++;
        maxFreq = std::max(maxFreq, freq[idx]);

        // If more than k replacements are needed, shrink the window
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            ++left;
        }

        result = max(result, right - left + 1);
    }

    return result;
}
```


***Testcases:***
```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
```

```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```
