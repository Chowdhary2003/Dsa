***Problem:***
```
You have been given two strings ‘STR1’ and ‘STR2’.

Your task is to find if ‘STR1’ is a subsequence of ‘STR2’.

A subsequence of a string is a new string that can be derived from the original string by deleting some characters (can be none) without changing the relative ordering of other characters.
```

> [!NOTE]
> 1.Strings ‘STR1’ and ‘STR2’ consists only of English uppercases.
> 2.Length of string ‘STR2’ will always be greater than or equal to the length of string ‘STR1’.


***Complexity:***
```
       Time Complexity: O(|STR2|)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <string>

bool isSubsequence(const string& str1, const string& str2) {
    size_t i = 0; // Index for str1
    size_t j = 0; // Index for str2

    while (i < str1.size() && j < str2.size()) {
        if (str1[i] == str2[j]) {
            ++i; // Move to next char in str1
        }
        ++j; // Always move in str2
    }

    return i == str1.size(); // True if all chars in str1 matched in order
}
```


***Testcases:***
```
Example:
‘ACE’ is a subsequence of ‘ABCDE’ because ‘ACE’ can be formed by deleting ‘B’ and ‘D’ without changing the relative order of characters. ‘ADB’ is not a subsequence of ‘ABCDE’ because we can get ‘ABD’ from ‘ABCDE’ but not ‘ADB’ and in ‘ADB’ relative order of ‘B’ and ‘D’ are different from original strings.
```


![Screenshot 2025-06-10 101703](https://github.com/user-attachments/assets/06bd0497-f537-4d91-a22f-6b6b7a087284)


```
Sample Input 1:
AE
BADE
AB
AC
Sample Output 1:
True
False
Explanation of sample input 1:
Test Case 1:

String ‘STR1’ is ‘AE’ and ‘STR2’ is ‘BADE’. All possible subsequences of ‘BADE’ are-

‘B’, ‘A’, ‘D’, ‘E’, ‘BA’, ‘BD’, ‘BE’, ‘AD’, ‘AE’, ‘DE’, ‘BAD’, ‘BAE’, ‘BDE’, ‘ADE’, ‘BADE’.
Hence ‘AE’ one of the subsequences of ‘BADE’
```

```
Test case 2:

String  ‘STR1’ is ‘AB’ and ‘STR2’ is ‘AC’.
There is no way to get string ‘AB’ from string ‘AC’ as character ‘B’ doesn’t exist in string ‘AC’.
Sample Input 2:
CB
BCDE
ABC
AHBDGC
Sample Output 2:
False
True
```
