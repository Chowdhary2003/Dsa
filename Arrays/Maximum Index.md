# Maximum Index

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
int maxIndexDiff(int arr[], int n) {
    if (n <= 1) {
        return 0;
    }

    // Initialize arrays
    vector<int> LMin(n);
    vector<int> RMax(n);

    // Fill LMin[] such that LMin[i] stores the minimum value from arr[0] to arr[i]
    LMin[0] = arr[0];
    for (int i = 1; i < n; i++) {
        LMin[i] = min(arr[i], LMin[i - 1]);
    }

    // Fill RMax[] such that RMax[j] stores the maximum value from arr[j] to arr[n-1]
    RMax[n - 1] = arr[n - 1];
    for (int j = n - 2; j >= 0; j--) {
        RMax[j] = max(arr[j], RMax[j + 1]);
    }

    // Traverse LMin[] and RMax[] to find the maximum j - i such that LMin[i] <= RMax[j]
    int i = 0, j = 0, maxDiff = -1;
    while (i < n && j < n) {
        if (LMin[i] <= RMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }

    return maxDiff;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
