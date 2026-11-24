***Problem :***
```
Ninja is provided a string, and he wants to return the first unique character in the string.

The string will contain characters only from the English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z').
If there is no non-repeating character, print the first character of the string
```
***Complexity :***
```
    Time Complexity: O(n)
    Space Complexity: O(1)
```


***Code :***
```cpp
#include <string>
#include <iostream>

char firstNonRepeatingCharacter(std::string str) {
    int freq[54] = {0};  // Array to hold frequency counts

    // Count the frequency of each character
    for (char c : str) {
        if (isupper(c)) {
            freq[c - 'A' + 26]++;  // Uppercase letters
        } else {
            freq[c - 'a']++;        // Lowercase letters
        }
    }

    // Find the first non-repeating character
    for (char c : str) {
        if (isupper(c)) {
            if (freq[c - 'A' + 26] == 1) {  // Check frequency for uppercase
                return c;
            }
        } else {
            if (freq[c - 'a'] == 1) {        // Check frequency for lowercase
                return c;
            }
        }
    }

    return str[0];  // Return first character if no non-repeating character is found
}
```

***Testcase :***
```
Sample Input :
aDcadhc
AabBcC

Sample Output :
 D
 A

Explanation for Sample Input :
In the first test case, ‘a’ is repeated.’ D’ is the first non-repeating character in the string, so we return it.

In the second test case, all the characters are non-repeating, so we return the first character.
```
