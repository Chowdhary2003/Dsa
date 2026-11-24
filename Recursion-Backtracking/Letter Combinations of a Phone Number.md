***Problem:***
```
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
```

<img src="https://github.com/user-attachments/assets/ac0dd566-a55a-4f7a-919d-adb8aaa4c935" width="500" />



***Complexity:***
```
       Time Complexity: Worst-case: O(4ⁿ)
       Space Complexity: O(4ⁿ), O(n)
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(const std::string& digits) {
        if (digits.empty()) return {};

        static const std::unordered_map<char, std::string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        std::vector<std::string> result;
        std::string current;
        current.reserve(digits.size());  // Avoid reallocations

        std::function<void(size_t)> backtrack = [&](size_t index) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }

            for (char c : phoneMap.at(digits[index])) {
                current.push_back(c);
                backtrack(index + 1);
                current.pop_back();  // backtrack
            }
        };

        backtrack(0);
        return result;
    }
};
```


***Testcases:***

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

```
Input: digits = ""
Output: []
```

```
Input: digits = "2"
Output: ["a","b","c"]
```
