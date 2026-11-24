***Problem:***
```
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)

```



***Code:***
```cpp
string largestOddSubstring(const string& num) {
    // Traverse the string from the end to the beginning
    for (int i = num.length() - 1; i >= 0; --i) {
        // Check if the current character is an odd digit
        if ((num[i] - '0') % 2 != 0) {  // Convert char to digit by subtracting '0'
            // Return the substring from the start to this position (inclusive)
            return num.substr(0, i + 1);
        }
    }
    // If no odd digit is found, return an empty string
    return "";
}
```


***Testcases:***
```
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
```
```
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
```
```
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.

```
