***Problem:***
```
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
- 't' that evaluates to true.
- 'f' that evaluates to false.
- '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
- '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
- '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.

Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool evaluateExpression(const string& expression) {
    stack<bool> evalStack;
    int idx = 0;

    // Helper function to evaluate the current character or subexpression
    function<bool()> parseExpr = [&]() {
        char current = expression[idx];

        if (current == 't') {
            idx++;  // Skip 't'
            return true;
        }
        if (current == 'f') {
            idx++;  // Skip 'f'
            return false;
        }

        if (current == '!') {
            idx++;  // Skip '!'
            idx++;  // Skip '('
            bool result = !parseExpr();  // Recursive call to handle inner expression
            idx++;  // Skip ')'
            return result;
        }

        if (current == '&' || current == '|') {
            char op = current;
            idx++;  // Skip '&' or '|'
            idx++;  // Skip '('
            
            // Handle the first subexpression
            bool result = parseExpr();
            
            // Handle the rest of the subexpressions
            while (expression[idx] == ',') {
                idx++;  // Skip ','
                bool subExprResult = parseExpr();
                result = (op == '&') ? (result && subExprResult) : (result || subExprResult);
            }
            
            idx++;  // Skip ')'
            return result;
        }
        
        return false;  // Default case
    };

    return parseExpr();  // Start parsing the expression
}
```


***Testcases:***
```
Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
```

```
Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
```

```
Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
```
