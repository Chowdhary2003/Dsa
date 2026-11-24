# First Repeating Element

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
int firstRepeated(int arr[], int n) {
    unordered_set<int> myset;
    int minIndex = n; // Initialize to a value greater than n to detect if no repeating element is found

    for (int i = n - 1; i >= 0; i--) {
        if (myset.find(arr[i]) != myset.end()) {
            minIndex = i; // Update the minIndex
        } else {
            myset.insert(arr[i]);
        }
    }

    if (minIndex < n) {
        return minIndex + 1; // Return the 1-indexed position of the first repeating element
    } else {
        return -1; // No repeating elements
    }
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
