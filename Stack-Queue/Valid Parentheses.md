***Problem:***
```
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n) in worst case, O(1) average
```



***Code:***
```cpp
#include <stack>
#include <string>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> stk;

    // Map closing brackets to their corresponding opening brackets
    static const std::unordered_map<char, char> bracketPairs{
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    for (char ch : s) {
        if (!bracketPairs.contains(ch)) {
            // Opening bracket, push onto stack
            stk.push(ch);
        } else {
            // Closing bracket: check stack top
            if (stk.empty() || stk.top() != bracketPairs.at(ch)) {
                return false;  // Mismatch or nothing to match
            }
            stk.pop();
        }
    }
    
    // If stack empty, all brackets matched properly
    return stk.empty();
}
```


***Testcases:***
```
Input: s = "()"
Output: true
```

```
Input: s = "()[]{}"
Output: true
```

```
Input: s = "(]"
Output: false
```

```
Input: s = "([])"
Output: true
```

```
Input: s = "([)]"

Output: false
```


***Testcases:***
```
Sample Input :
[()]{}{[()()]()}

Sample Output :
Balanced

Explanation Of the Sample Input :
There is always an opening brace before a closing brace i.e. '{' before '}', '(' before '), '[' before ']'.
So the 'S' is Balanced.
```

```
Sample Input :
[[}[
Sample Output :
Not Balanced
```
