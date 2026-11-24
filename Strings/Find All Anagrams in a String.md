***Problem:***
```
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
```



***Complexity:***
```
       Time Complexity: O(|s|)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <array>

using namespace std;

vector<int> findAnagrams(const string& s, const string& p) {
    if (p.size() > s.size()) return {};

    constexpr int CHAR_COUNT = 26;
    array<int, CHAR_COUNT> countP{}, countS{};  // Frequency arrays for 'a' to 'z'

    // Build frequency count for p
    for (char c : p) {
        countP[c - 'a']++;
    }

    vector<int> result;
    int windowSize = p.size();

    // Initialize sliding window frequency for first window (except last char)
    for (int i = 0; i < windowSize - 1; ++i) {
        countS[s[i] - 'a']++;
    }

    // Slide over s
    for (int i = windowSize - 1; i < (int)s.size(); ++i) {
        // Add new char to current window
        countS[s[i] - 'a']++;

        // Check if current window matches p's frequency
        if (countS == countP) {
            result.push_back(i - windowSize + 1);
        }

        // Remove oldest char from window
        countS[s[i - windowSize + 1] - 'a']--;
    }

    return result;
}

```


***Testcases:***
```
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

```
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
```
