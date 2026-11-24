# Find minimum and maximum element in an array

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
pair<long long, long long> getMinMax(long long a[], int n) {
        // code here
         long long minElement = *min_element(a, a + n);
    long long maxElement = *max_element(a, a + n);
    
    // Return them as a pair
    return make_pair(minElement, maxElement);
    }
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
