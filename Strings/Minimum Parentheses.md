***Problem:***
```
A parentheses string is valid if and only if:
- It is the empty string,
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.

You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
- For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".

Return the minimum number of moves required to make s valid.
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
    int minAddToMakeValid(const string& s) {
        int balance = 0;  // Tracks unmatched '('
        int insertions = 0;  // Tracks unmatched ')'
        
        for (char ch : s) {
            if (ch == '(') {
                ++balance;
            } else { // ch == ')'
                if (balance > 0) {
                    --balance; // Match with an open '('
                } else {
                    ++insertions; // Need to insert a '('
                }
            }
        }
        
        // Remaining '(' need ')' to balance
        return insertions + balance;
    }
};
```


***Testcases:***
```
Input: s = "())"
Output: 1
```

```
Input: s = "((("
Output: 3
```

```
Sample Input 1:
)((()
((
Sample Output 1:
3
2
```

![Screenshot 2025-06-04 184204](https://github.com/user-attachments/assets/9bc459e7-2dc7-4631-8d26-97b8594d31cf)


![Screenshot 2025-06-04 184214](https://github.com/user-attachments/assets/0c54ff41-2242-4fcc-9a98-3a6ada0131e3)

