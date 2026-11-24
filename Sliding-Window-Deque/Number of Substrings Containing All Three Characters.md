***Problem:***
```
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int countSubstringsWithABC(const string& s) {
    int n = s.size();
    unordered_map<char, int> freq;
    int count = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        ++freq[s[right]];

        // Shrink the window from the left while all three chars are present
        while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
            // All substrings from current 'right' to end are valid
            count += (n - right);
            --freq[s[left++]];
        }
    }
    return count;
}
```


***Testcases:***
```
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
```

```
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
```

```
Input: s = "abc"
Output: 1
```
