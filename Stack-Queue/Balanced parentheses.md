# Balanced parentheses

## Problem

The implementation checks whether the delimiters in an expression are balanced. Opening parentheses, square brackets, and curly braces must be closed by the matching type in the correct order.

> **Note:** This problem description was inferred from the supplied C++ implementation; the original problem statement was not included in the archive.

## C++ Solution

```cpp
bool isValidParenthesis(string expression) {
    stack<char> s;
    
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);  // Push opening parentheses onto the stack
        } else {
            if (s.empty()) {
                return false;  // Stack is empty, no matching opening parenthesis
            }
            
            char top = s.top();
            s.pop();
            
            // Check if the current closing parenthesis matches the top of the stack
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;  // Mismatched parentheses
            }
        }
    }
    
    return s.empty();  // Stack should be empty if all parentheses are matched
}
```
