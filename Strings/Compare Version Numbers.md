***Problem:***
```
Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:
- If version1 < version2, return -1.
- If version1 > version2, return 1.
- Otherwise, return 0.
```



***Complexity:***
```
       Time Complexity: O(max(N1, N2))
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <string>
#include <cctype>
#include <iostream>

int compareVersion(const std::string& version1, const std::string& version2) {
    size_t i = 0, j = 0;
    const size_t n1 = version1.size(), n2 = version2.size();
    
    while (i < n1 || j < n2) {
        int v1 = 0, v2 = 0;

        // Parse next revision from version1
        while (i < n1 && version1[i] != '.') {
            v1 = v1 * 10 + (version1[i] - '0');
            ++i;
        }
        // Parse next revision from version2
        while (j < n2 && version2[j] != '.') {
            v2 = v2 * 10 + (version2[j] - '0');
            ++j;
        }

        if (v1 < v2) return -1;
        if (v1 > v2) return 1;

        ++i; // skip dot
        ++j; // skip dot
    }

    return 0; // all revisions are equal
}
```


***Testcases:***
```
Input: version1 = "1.2", version2 = "1.10"

Output: -1

Explanation:
version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.
```

```
Input: version1 = "1.01", version2 = "1.001"

Output: 0

Explanation:
Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
```

```
Input: version1 = "1.0", version2 = "1.0.0.0"

Output: 0

Explanation:
version1 has less revisions, which means every missing revision are treated as "0".
```
