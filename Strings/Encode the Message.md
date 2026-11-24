***Problem:***
```
You have been given a text message. You have to return the Run-length Encoding of the given message.

Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as the character and a single count. For example, the string "aaaabbbccdaa" would be encoded as "a4b3c2d1a2".
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <sstream>
#include <string>

// Run-Length Encoding function
string runLengthEncode(const string& input) {
    if (input.empty()) return "";

    ostringstream encoded;
    int count = 1;

    for (size_t i = 1; i <= input.size(); ++i) {
        // Check if the current char is different from the previous
        if (i == input.size() || input[i] != input[i - 1]) {
            encoded << input[i - 1] << count;
            count = 1; // reset count for the next char
        } else {
            ++count; // same character, increase count
        }
    }

    return encoded.str();
}
```


***Testcases:***
```
Sample Input 1 :
aabbc
abcd
abbdcaas
Sample Output 1 :
a2b2c1
a1b1c1d1
a1b2d1c1a2s1
Explaination for Sample Input 1:
Test Case 1: As 2 consecutive 'a', 2 consecutive 'b', and 1 'c' are present in the given string so output is "a2b2c1".

Test Case 2: As 1 consecutive 'a', 1 consecutive 'b', 1 consecutive 'c' and 1 consecutive 'd' are present in the given string so output is "a1b1c1d1".

Test Case 3: As 1 consecutive 'a', 2 consecutive 'b', 1 consecutive 'd', 1consecutive 'c', 2 consecutive 'a' and 1 consecutive 's' are present in the given string so output is "a1b2d1c1a2s1".
```

```
Sample Input 2:
sadasd
adsad
Sample Output 2:
s1a1d1a1s1d1
a1d1s1a1d1
```
