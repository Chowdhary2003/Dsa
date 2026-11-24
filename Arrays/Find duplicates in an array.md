# Find duplicates in an array

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity. Add an analysis after reviewing the algorithm.

## C++ solution

```cpp
vector<int> duplicates(long long arr[], int n) {
    // Step 1: Create an empty unordered map to store element frequencies
    unordered_map<long long, int> freqMap;
    vector<int> result;

    // Step 2: Iterate through the array and count element frequencies
    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    // Step 3: Iterate through the hashmap to find duplicates
    for (auto& entry : freqMap) {
        if (entry.second > 1) {
            result.push_back(entry.first);
        }
    }

    // Step 4: If no duplicates found, add -1 to the result
    if (result.empty()) {
        result.push_back(-1);
    }
    //step 5: sort the result
    sort(result.begin(),result.end());
    // Step 6: Return the result vector containing duplicate elements or -1
    return result;
}
```

## Review notes

- The original source text is preserved in the code block.
- Check judge-provided headers, types, and function signatures before standalone compilation.
- Add the problem statement, intuition, dry run, and test cases after confirming the original problem requirements.
