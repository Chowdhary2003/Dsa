# Return Subsets Sum to K

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Generate subsets of the input array whose selected elements add up to K. The implementation explores include/exclude choices recursively and stores matching selections.

## C++ Implementation

```cpp
void findSubsets(vector<int>& arr, int index, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (index >= arr.size() || target < 0) {
        return;
    }
    current.push_back(arr[index]);
    findSubsets(arr, index + 1, target - arr[index], current, result);
    current.pop_back();
    findSubsets(arr, index + 1, target, current, result);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int>& arr, int k) {
    vector<vector<int>> result;
    vector<int> current;
    sort(arr.begin(), arr.end()); // Sort the array for unique subsets
    findSubsets(arr, 0, k, current, result);
    return result;
}
```
