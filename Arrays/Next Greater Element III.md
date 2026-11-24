***Problem:***
```
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
```



***Complexity:***
```
       Time Complexity: O(d)
       Space Complexity: O(d)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX
#include <iostream>

int nextGreaterElement(int n) {
    std::vector<int> digits;

    // Extract digits from n, least significant digit last
    int temp = n;
    while (temp > 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    std::reverse(digits.begin(), digits.end());

    // Step 1: Find pivot: rightmost digit smaller than the digit after it
    int i = static_cast<int>(digits.size()) - 2;
    while (i >= 0 && digits[i] >= digits[i + 1]) {
        --i;
    }

    if (i < 0) return -1; // no next permutation possible

    // Step 2: Find rightmost digit larger than digits[i]
    int j = static_cast<int>(digits.size()) - 1;
    while (digits[j] <= digits[i]) {
        --j;
    }

    // Step 3: Swap pivot with this digit
    std::swap(digits[i], digits[j]);

    // Step 4: Reverse suffix after i
    std::reverse(digits.begin() + i + 1, digits.end());

    // Convert digits back to int safely
    long long result = 0;
    for (int d : digits) {
        result = result * 10 + d;
        if (result > INT_MAX) return -1; // overflow check
    }

    return static_cast<int>(result);
}
```


***Testcases:***
```
Input: n = 12
Output: 21
```

```
Input: n = 21
Output: -1
```
