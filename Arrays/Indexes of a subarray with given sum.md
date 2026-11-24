# Indexes of a subarray with given sum

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
vector<int> subarraySum(vector<int> arr, int n, long long s) {
    int start = 0;
    int end = 0;
    long long currentSum = arr[0];
    
    while (end < n) {
        if (currentSum == s) {
            return {start + 1, end + 1}; // Adding 1 to convert to 1-based indexing
        }
        
        if (currentSum < s || start == end) {
            end++;
            if (end < n) {
                currentSum += arr[end];
            }
        } else {
            currentSum -= arr[start];
            start++;
        }
    }

    return {-1};
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
