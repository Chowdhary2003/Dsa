***Problem:***
```
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
    string removeKdigits(string num, int k) {
    string result;

    for (char digit : num) {
        // Remove digits from result while we can, and while the last digit is greater than the current digit
        while (!result.empty() && k > 0 && result.back() > digit) {
            result.pop_back();
            --k;
        }
        result.push_back(digit);
    }

    // If we still need to remove more digits, remove from the end
    while (k-- > 0 && !result.empty()) {
        result.pop_back();
    }

    // Remove leading zeros
    size_t nonZeroIdx = result.find_first_not_of('0');
    result = (nonZeroIdx != string::npos) ? result.substr(nonZeroIdx) : "0";

    return result.empty() ? "0" : result;
    }
```


***Testcases:***
```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```

```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```
