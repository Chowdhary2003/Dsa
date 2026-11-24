***Problem:***
```
You are given a number 'N' in the form of a string 'S', your task is to find the smallest number strictly greater than the given number 'N' which is a palindrome.
```


> [!NOTE]
> 1) A palindrome is a word, number, phrase, or another sequence of characters that reads the same backward as forward, such as 'naman', 'abcba', '1234321', etc
> 2) The numerical value of the given string 'S' will be greater than 0.
> 3) A single-digit number is also considered as a palindrome.
> 4) Note that the length of the string 'S' is nothing but the number of digits in the number 'N'.


***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <string>
#include <algorithm>


// Helper: Increment a numeric string with possible carry
string increment(const string& s) {
    string result = s;
    int i = s.size() - 1;
    while (i >= 0 && result[i] == '9') {
        result[i] = '0';
        --i;
    }
    if (i < 0) {
        result = "1" + result;
    } else {
        result[i]++;
    }
    return result;
}

// Main function: Finds the next palindrome strictly greater than s
string nextPalindrome(const string& s) {
    int n = s.size();
    
    // Edge case: All 9s
    if (all_of(s.begin(), s.end(), [](char c){ return c == '9'; })) {
        return "1" + string(n - 1, '0') + "1";
    }

    int mid = n / 2;
    bool isOdd = n % 2;

    string left = s.substr(0, mid);
    string midChar = isOdd ? s.substr(mid, 1) : "";
    string mirror = left + midChar + string(left.rbegin(), left.rend());

    if (mirror > s) {
        return mirror;
    }

    // Increment the left+middle part
    string leftPlusMid = left + midChar;
    string incremented = increment(leftPlusMid);

    // Rebuild palindrome from incremented part
    string newLeft = incremented.substr(0, mid);
    string newMid = isOdd ? incremented.substr(mid, 1) : "";
    string result = newLeft + newMid + string(newLeft.rbegin(), newLeft.rend());

    return result;
}

// Helper: Checks if a string is a palindrome
bool isPalindrome(const string& s) {
    return nextPalindrome(s);
}
```


***Testcases:***
```
Sample Input 1:
4
1221
Sample Output 1:
1331
Explanation for sample input 1:
The next smaller palindrome to 1221 is 1331, as it is strictly greater than 1221 and it reads the same from the front and back both.
```

```
Sample Input 2:
3
999
Sample Output 2:
1001
Explanation for sample input 1:
The next smaller palindrome to 999 is 1001, as it is strictly greater than 999 and it reads the same from the front and back both.
```
