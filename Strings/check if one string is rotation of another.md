***Problem:***
```
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```
bool canBeShifted(const string& s, const string& goal) {
    // Check if the strings have the same length
    if (s.length() != goal.length()) {
        return false;
    }

    // Concatenate s with itself and check if goal is a substring
    return (s + s).find(goal) != string::npos;
}
```


***Testcases:***
```
Input: s = "abcde", goal = "cdeab"
Output: true
```
```
Input: s = "abcde", goal = "abced"
Output: false

```
