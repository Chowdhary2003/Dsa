# Print all subsequences or Power Set

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Generate the power set of the input array, including the empty subset. The implementation builds subsets iteratively by appending each value to the subsets already produced.

## C++ Implementation

```cpp
/*

Time Complexity: O(2^n) 
Space Complexity: O(2^n * n)

*/
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result = {{}}; // Add the empty subset
    for (int num : nums) {
        int size = result.size();
        for (int i = 0; i < size; i++) {
            vector<int> subset = result[i];
            subset.push_back(num);
            result.push_back(subset);
        }
    }
    return result;
}
```
