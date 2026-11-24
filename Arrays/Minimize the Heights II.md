# Minimize the Heights II

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - k < 0) continue;
        int tempMin = min(arr[0] + k, arr[i] - k);
        int tempMax = max(arr[i - 1] + k, arr[n - 1] - k);
        ans = min(ans, tempMax - tempMin);
    }
    return ans;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
