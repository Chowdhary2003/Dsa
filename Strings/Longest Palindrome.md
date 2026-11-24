***Problem:***
```
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(k), where k is the alphabet size (52 for uppercase + lowercase)
```



***Code:***
```cpp
#include <string>
#include <unordered_map>

class Solution {
public:
    int longestPalindrome(const std::string& s) {
        std::unordered_map<char, int> freq;
        for (char ch : s) {
            ++freq[ch];
        }

        int length = 0;
        bool odd_found = false;

        for (const auto& [ch, count] : freq) {
            length += (count / 2) * 2; // add the largest even number <= count
            if (count % 2 == 1) {
                odd_found = true;
            }
        }

        if (odd_found) {
            ++length; // add 1 center character if any odd count exists
        }

        return length;
    }
};
```


***Testcases:***
```
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
```

```
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
```
