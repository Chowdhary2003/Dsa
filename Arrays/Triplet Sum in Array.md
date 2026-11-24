# Triplet Sum in Array

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
bool find3Numbers(int A[], int n, int X) {
    sort(A, A + n);
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (A[i] + A[l] + A[r] == X) {
                return true;
            } else if (A[i] + A[l] + A[r] < X) {
                l++;
            } else {
                r--;
            }
        }
    }
    return false;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
