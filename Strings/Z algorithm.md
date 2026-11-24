# Z algorithm

> Converted from the original standalone C++ file. The implementation below is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
#include <vector>

#include <string>

// Function to calculate the Z array of a given string

std::vector<int> calculateZArray(const std::string& str) {

    int n = str.length();

    std::vector<int> zArray(n);

    int left = 0, right = 0;

    for (int i = 1; i < n; i++) {

        if (i <= right)

            zArray[i] = std::min(right - i + 1, zArray[i - left]);

        // Matching characters beyond the known Z-box

        while (i + zArray[i] < n && str[zArray[i]] == str[i + zArray[i]])

            zArray[i]++;

        // Updating the Z-box boundaries

        if (i + zArray[i] - 1 > right) {

            left = i;

            right = i + zArray[i] - 1;

        }

    }

    return zArray;

}

// Function to count the occurrences of a pattern in a text using the Z array

int countPatternOccurrences(const std::string& text, const std::string& pattern) {

    std::string concat = pattern + "#" + text;

    int patternLength = pattern.length();

    int totalLength = concat.length();

    // Calculate the Z array of the concatenated string

    std::vector<int> zArray = calculateZArray(concat);

    int count = 0;

    for (int i = patternLength + 1; i < totalLength; i++) {

        // If Z value at position i equals the length of the pattern,

        // increment the count of pattern occurrences

        if (zArray[i] == patternLength)

            count++;

    }

    return count;

}
```

## Review notes

- The source code was transferred without changing its implementation.
- Check required headers, namespace declarations, and platform-specific function signatures before compiling standalone.
- Add problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
