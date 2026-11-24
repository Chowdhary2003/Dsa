# Alternate +ve,-ve nums

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
vector<int> RearrangebySign(vector<int> A) {
    int n = A.size();

    // Define array for storing the result separately.
    vector<int> ans(n, 0);

    // positive elements start from index 0 and negative elements from index 1.
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        // Fill negative elements in odd indices and increment by 2.
        if (A[i] < 0) {
            ans[negIndex] = A[i];
            negIndex += 2;
        }
        // Fill positive elements in even indices and increment by 2.
        else {
            ans[posIndex] = A[i];
            posIndex += 2;
        }
    }

    return ans;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
