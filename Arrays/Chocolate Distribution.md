# Chocolate Distribution

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
#include <vector>
#include <algorithm>
#include <climits>

long long findMinDiff(std::vector<long long> a, long long n, long long m) {
    if (m == 0 || n == 0) return 0;
    if (m > n) return -1;
    long long mini = LLONG_MAX;

    std::sort(a.begin(), a.end());

    for (long long i = 0; i + m - 1 < n; i++) {
        if (a[i + m - 1] - a[i] < mini) {
            mini = a[i + m - 1] - a[i];
        }
    }
    return mini;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
