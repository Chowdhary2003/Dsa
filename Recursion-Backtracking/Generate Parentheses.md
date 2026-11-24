***Problem:***
```
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

```



***Complexity:***
```
       Time Complexity: O(n · 4ⁿ / √n)
       Space Complexity: O(n · 4ⁿ / √n)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <string>

void generateParenthesisHelper(int open, int close, int n, string current, vector<string>& result) {
    // Base case: if the current string has n open and n close parentheses, it's valid
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }

    // If we can still add an open parenthesis, add it
    if (open < n) {
        generateParenthesisHelper(open + 1, close, n, current + '(', result);
    }

    // If we can still add a close parenthesis, add it
    if (close < open) {
        generateParenthesisHelper(open, close + 1, n, current + ')', result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(0, 0, n, "", result);  // Start with 0 open and 0 close parentheses
    return result;
}
```


***Testcases:***
```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

```
Input: n = 1
Output: ["()"]
```
