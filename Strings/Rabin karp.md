# Rabin karp

> Converted from the original standalone C++ file. The implementation below is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
vector<int> stringMatch(string& str, string& pat) {
    int n = str.length();
    int m = pat.length();
    vector<int> occurrences;

    // Calculate the hash value of the pattern
    int patternHash = 0;
    for (char c : pat) {
        patternHash += c;
    }

    // Calculate the initial hash value of the first window in the text
    int windowHash = 0;
    for (int i = 0; i < m; i++) {
        windowHash += str[i];
    }

    // Check each window in the text for a match with the pattern
    for (int i = 0; i <= n - m; i++) {
        // Compare the hash values of the window and the pattern
        if (windowHash == patternHash) {
            // Verify the actual characters for false positive matches
            int j;
            for (j = 0; j < m; j++) {
                if (str[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == m) {
                occurrences.push_back(i);
            }
        }

        // Update the hash value for the next window in the text
        windowHash -= str[i];
        if (i + m < n) {
            windowHash += str[i + m];
        }
    }

    return occurrences;
}
```

## Review notes

- The source code was transferred without changing its implementation.
- Check required headers, namespace declarations, and platform-specific function signatures before compiling standalone.
- Add problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
