# Subarray with 0 sum

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
bool subArrayExists(int arr[], int N)
{
    unordered_set<int> sumSet;
 
    // Traverse through array and store prefix sums
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
 
        // If prefix sum is 0 or it is already present
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
