***Problem:***
```
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```


Supports only + and - operators

***Code:***
```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for isdigit and isspace

int calculate(const std::string& s) {
    std::stack<int> stk; // Stack to keep previous results
    int result = 0;       // Current evaluated result
    int num = 0;          // Current number being parsed
    int sign = 1;         // Current sign: 1 for '+', -1 for '-'

    for (size_t i = 0; i < s.length(); ++i) {
        char ch = s[i];

        if (std::isdigit(ch)) {
            num = num * 10 + (ch - '0'); // Build multi-digit numbers
        } 
        else if (ch == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } 
        else if (ch == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } 
        else if (ch == '(') {
            // Save current state
            stk.push(result);
            stk.push(sign);
            // Reset for new sub-expression
            result = 0;
            sign = 1;
        } 
        else if (ch == ')') {
            result += sign * num;
            num = 0;
            int prev_sign = stk.top(); stk.pop();
            int prev_result = stk.top(); stk.pop();
            result = prev_result + prev_sign * result;
        }
        // Ignore spaces
    }

    result += sign * num; // Last number, if any
    return result;
}
```


Supports + - * / operators

```cpp
class Solution {
public:
    int calculate(const std::string& s) {
        int i = 0;
        return evaluate(s, i);
    }

private:
    int evaluate(const std::string& s, int& i) {
        std::vector<int> stack;
        int num = 0;
        char op = '+';

        while (i < s.size()) {
            char c = s[i];
            bool needIncrement = true;

            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '(') {
                ++i;  // move past '('
                num = evaluate(s, i);
                needIncrement = false;  // i already updated by recursion
            }

            if ((!std::isdigit(c) && !std::isspace(c)) || i == s.size() - 1) {
                switch (op) {
                    case '+': stack.push_back(num); break;
                    case '-': stack.push_back(-num); break;
                    case '*': {
                        int last = stack.back();
                        stack.pop_back();
                        stack.push_back(last * num);
                        break;
                    }
                    case '/': {
                        int last = stack.back();
                        stack.pop_back();
                        stack.push_back(last / num);
                        break;
                    }
                }
                num = 0;

                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    op = c;
                }

                if (c == ')') {
                    ++i;  // move past ')'
                    break;
                }
            }

            if (needIncrement) ++i;
        }

        int result = 0;
        for (int val : stack) result += val;
        return result;
    }
};
```


***Testcases:***
```
Input: s = "1 + 1"
Output: 2
```

```
Input: s = " 2-1 + 2 "
Output: 3
```

```
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
```
