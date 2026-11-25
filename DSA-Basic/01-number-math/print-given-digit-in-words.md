# Print given digit in words

## Problem
```
Given a number N, the task is to convert every digit of the number into words.
```



## Complexity
```
       Time Complexity: O(d)
       Space Complexity: O(d)
```



## Solution
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string digitsToWords(int N) {
    // Map digits to words
    static const std::vector<std::string> digitWords{
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    // Handle zero explicitly
    if (N == 0) return digitWords[0];

    // Convert number to string for easy traversal
    std::string numStr = std::to_string(N);

    std::string result;
    for (size_t i = 0; i < numStr.size(); ++i) {
        char ch = numStr[i];
        // Since input is guaranteed digits, no need for error checking here
        int digit = ch - '0';
        result += digitWords[digit];
        if (i != numStr.size() - 1) {
            result += ' ';
        }
    }
    return result;
}
```


## Examples
```
Input: N = 1234 
Output: One Two Three Four 
Explanation: 
Every digit of the given number has been converted into its corresponding word.
```

```
Input: N = 567 
Output: Five Six Seven 
```
