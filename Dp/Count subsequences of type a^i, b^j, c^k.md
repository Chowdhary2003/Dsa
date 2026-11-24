***Problem:***
```
Given a string S, the task is to count number of subsequences of the form aⁱbʲcᵏ, where i >= 1, j >=1 and k >= 1.

Note: 
1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
2.  For large test cases, the output value will be too large, return the answer MODULO 10^9+7
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <string>

constexpr static int MOD = 1'000'000'007;

int countSubsequences(const std::string& s) {
    long long countA = 0;    // Subsequences with only 'a's
    long long countAB = 0;   // Subsequences with 'a's followed by 'b's
    long long countABC = 0;  // Subsequences with 'a's followed by 'b's followed by 'c's

    for (char ch : s) {
        if (ch == 'a') {
            // New 'a' can start a subsequence or extend existing 'a' subsequences
            countA = (2 * countA + 1) % MOD;
        } else if (ch == 'b') {
            // New 'b' can extend 'a' subsequences to 'ab' subsequences or extend existing 'ab' subsequences
            countAB = (2 * countAB + countA) % MOD;
        } else if (ch == 'c') {
            // New 'c' can extend 'ab' subsequences to 'abc' subsequences or extend existing 'abc' subsequences
            countABC = (2 * countABC + countAB) % MOD;
        }
        // Ignore other characters (if any)
    }
    return static_cast<int>(countABC);
}
```


***Testcases:***
```
Input:
S = "abbc"
Output: 3
Explanation: Subsequences are abc, abc and abbc.
```

```
Input:
S = "abcabc"
Output: 7
Explanation: Subsequences are abc, abc,
abbc, aabc abcc, abc and abc.
```
