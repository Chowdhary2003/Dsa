***Problem:***
```
Given two binary strings a and b, return their sum as a binary string.
```



***Complexity:***
```
       Time Complexity: O(max(n, m))
       Space Complexity: O(max(n, m))
```



***Code:***
```cpp
#include <string>
#include <algorithm> // for std::reverse

std::string addBinary(const std::string& a, const std::string& b) {
    std::string result;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';  // Convert char to int
        if (j >= 0) sum += b[j--] - '0';

        result += (sum % 2) + '0';        // Append binary digit
        carry = sum / 2;                  // Compute carry
    }

    std::reverse(result.begin(), result.end());
    return result;
}
```


***Testcases:***
```
Input: a = "11", b = "1"
Output: "100"
```

```
Input: a = "1010", b = "1011"
Output: "10101"
```
