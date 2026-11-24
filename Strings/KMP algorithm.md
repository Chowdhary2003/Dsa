# KMP algorithm

> Converted from the original standalone C++ file. The implementation below is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
#include <vector>

#include <string>

bool findPattern(const std::string& pattern, const std::string& text) {

    int m = pattern.size();

    int n = text.size();

    // Construct the LPS (Longest Proper Prefix which is also Suffix) array

    std::vector<int> lps(m, 0);

    int len = 0;  // Length of the previous longest prefix suffix

    for (int i = 1; i < m; ++i) {

        if (pattern[i] == pattern[len]) {

            ++len;

            lps[i] = len;

        } else {

            if (len != 0) {

                len = lps[len - 1];

                --i;  // Decrease i to recheck the current character

            } else {

                lps[i] = 0;

            }

        }

    }

    // Perform pattern matching

    int i = 0;  // Index for text

    int j = 0;  // Index for pattern

    while (i < n) {

        if (pattern[j] == text[i]) {

            ++i;

            ++j;

            if (j == m) {

                return true;  // Pattern found

            }

        } else {

            if (j != 0) {

                j = lps[j - 1];

            } else {

                ++i;

            }

        }

    }

    return false;  // Pattern not found

}
```

## Review notes

- The source code was transferred without changing its implementation.
- Check required headers, namespace declarations, and platform-specific function signatures before compiling standalone.
- Add problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
