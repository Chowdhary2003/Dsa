# First non-repeating element

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
int firstNonRepeating(int arr[], int n)
{
    // Insert all array elements in hash
    // table
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
 
    // Traverse array again and return
    // first element with count 1.
    for (int i = 0; i < n; i++)
        if (mp[arr[i]] == 1)
            return arr[i];
    return 0;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
