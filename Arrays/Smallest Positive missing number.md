# Smallest Positive missing number

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
1.int firstMissingPos(int A[], int n)
{

    // To mark the occurrence of elements
    bool present[n + 1] = { false };

    // Mark the occurrences
    for (int i = 0; i < n; i++) {

        // Only mark the required elements
        // All non-positive elements and the elements
        // greater n + 1 will never be the answer
        // For example, the array will be {1, 2, 3} in the
        // worst case and the result will be 4 which is n +
        // 1
        if (A[i] > 0 && A[i] <= n)
            present[A[i]] = true;
    }

    // Find the first element which didn't appear in the
    // original array
    for (int i = 1; i <= n; i++)
        if (!present[i])
            return i;

    // If the original array was of the type {1, 2, 3} in
    // its sorted form
    return n + 1;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
