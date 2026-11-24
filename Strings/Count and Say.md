***Problem:***
```
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
- countAndSay(1) = "1"
- countAndSay(n) is the run-length encoding of countAndSay(n - 1).

Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.
```



***Complexity:***
```
       Time Complexity: O(2^n)
       Space Complexity: O(T(n))
```



***Code:***
```cpp
#include <string>

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 1; i < n; ++i) {
            string next;
            int len = result.size();
            for (int j = 0; j < len;) {
                char current_char = result[j];
                int count = 0;
                // Count consecutive matching digits
                while (j < len && result[j] == current_char) {
                    ++count;
                    ++j;
                }
                // Append count and digit
                next += to_string(count) + current_char;
            }
            result = move(next);
        }
        
        return result;
    }
};
```


***Testcases:***
```
Input: n = 4
Output: "1211"

Explanation:
countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
```

```
Input: n = 1
Output: "1"

Explanation:
This is the base case.
```
