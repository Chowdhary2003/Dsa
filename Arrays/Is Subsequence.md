***Problem :***
```
You have been given two strings ‘STR1’ and ‘STR2’.
Your task is to find if ‘STR1’ is a subsequence of ‘STR2’.

A subsequence of a string is a new string that can be derived from the original string by deleting some characters
(can be none) without changing the relative ordering of other characters.
```

***Complexity :***
```
Time Complexity: O(n) 
Space Complexity: O(1)
```


***Code :***

```cpp
#include <string>

bool isSubsequence(const std::string& s, const std::string& t) {
    int n = s.length(); // Length of string s
    int m = t.length(); // Length of string t
    
    int j = 0; // Index for string s
    
    // Traverse string t
    for (int i = 0; i < m; ++i) {
        if (j < n && s[j] == t[i]) {
            ++j; // Move to the next character in s
        }
    }
    
    // If we've matched all characters in s, j should be equal to n
    return j == n;
}
```



***Test cases :***
```
Sample Input :
AE
BADE

AB
AC

Sample Output :
True

False

Explanation of sample input :
Test Case 1:

String ‘STR1’ is ‘AE’ and ‘STR2’ is ‘BADE’. All possible subsequences of ‘BADE’ are-

‘B’, ‘A’, ‘D’, ‘E’, ‘BA’, ‘BD’, ‘BE’, ‘AD’, ‘AE’, ‘DE’, ‘BAD’, ‘BAE’, ‘BDE’, ‘ADE’, ‘BADE’.
Hence ‘AE’ one of the subsequences of ‘BADE’


Test case 2:

String  ‘STR1’ is ‘AB’ and ‘STR2’ is ‘AC’.
There is no way to get string ‘AB’ from string ‘AC’ as character ‘B’ doesn’t exist in string ‘AC’.
```


```
Sample Input :
CB
BCDE

ABC
AHBDGC

Sample Output :
False
True
```
