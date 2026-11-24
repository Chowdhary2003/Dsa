***Problem:***
```
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:
- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <string>

class Solution {
public:
    bool checkValidString(const string& s) {
        int low = 0, high = 0; // Track min and max possible open parentheses

        for (char c : s) {
            if (c == '(') {
                ++low;
                ++high;
            } else if (c == ')') {
                --low;
                --high;
            } else { // c == '*'
                --low;  // treat '*' as ')'
                ++high; // or treat '*' as '('
            }

            if (high < 0)
                return false; // Too many ')'

            if (low < 0)
                low = 0; // Can't have negative open count
        }

        return low == 0; // If min open is 0, there's a valid interpretation
    }
};
```


***Testcases:***
```
Input: s = "()"
Output: true
```

```
Input: s = "(*)"
Output: true
```

```
Input: s = "(*))"
Output: true
```
