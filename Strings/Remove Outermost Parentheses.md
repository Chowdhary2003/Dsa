***Problem:***
```
Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)

```



***Code:***
```
string removeOuterParentheses(const string& s) {
    string result;
    int balance = 0;
    
    for (char c : s) {
        if (c == '(') {
            // If balance > 0, it's not the outermost '('
            if (balance > 0) {
                result += c;
            }
            balance++;
        } else {
            balance--;
            // If balance > 0, it's not the outermost ')'
            if (balance > 0) {
                result += c;
            }
        }
    }
    
    return result;
}
```


***Testcases:***
```
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
```
```
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
```
```
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".

```
