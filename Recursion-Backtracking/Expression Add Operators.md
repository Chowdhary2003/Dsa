
***Problem:***
```
Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.
```



***Complexity:***
```
       Time Complexity: O(4^n * n)
       Space Complexity: O(n) (call stack) + O(4^n × n) (result list)
```



***Code:***
```cpp
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, "", 0, 0, result);
        return result;
    }

private:
    void backtrack(const string& num, int target, int index, string expr, long long eval, long long prev, vector<string>& result) {
        if (index == num.size()) {
            if (eval == target) result.push_back(expr);
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            // Prevent operands with leading zeros
            if (i != index && num[index] == '0') break;

            string currStr = num.substr(index, i - index + 1);
            long long curr = stoll(currStr);

            if (index == 0) {
                // First number: just pass it without any operator
                backtrack(num, target, i + 1, currStr, curr, curr, result);
            } else {
                // Addition
                backtrack(num, target, i + 1, expr + '+' + currStr, eval + curr, curr, result);
                // Subtraction
                backtrack(num, target, i + 1, expr + '-' + currStr, eval - curr, -curr, result);
                // Multiplication
                backtrack(num, target, i + 1, expr + '*' + currStr, eval - prev + prev * curr, prev * curr, result);
            }
        }
    }
};
```


***Testcases:***
```
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
```


```
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
```


```
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
```
