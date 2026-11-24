***Problem:***
```
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
```



***Complexity:***
```
       Time Complexity: O(n * m)
       Space Complexity: O(m)
```



***Code:***
```cpp
string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) return "";  // Edge case: if the vector is empty, return an empty string.

    // Start by assuming the first string is the common prefix.
    string prefix = strs[0];

    // Compare the prefix with each string in the array.
    for (const auto& str : strs) {
        // Compare the prefix with the current string
        int i = 0;
        while (i < prefix.size() && i < str.size() && prefix[i] == str[i]) {
            ++i;
        }
        prefix = prefix.substr(0, i);  // Update prefix to the matched portion
        if (prefix.empty()) return "";  // If no common prefix, return an empty string.
    }

    return prefix;
}
```


***Testcases:***
```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```
```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

```
