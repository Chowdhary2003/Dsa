# Subset Sum Equal To K

**Problem statement:** The original `.cpp` file contains an implementation but does not include a complete problem statement. The title is taken from the source filename; consult the original problem source for exact wording, constraints, and examples.

**C++ implementation:**
```cpp

bool isSubsetSum(vector<int> arr, int sum) {
    // Create a boolean array to store the subset sum possibilities
    vector<bool> dp(sum + 1, false);
    
    // Base case: If the target is 0, an empty subset can achieve this sum
    dp[0] = true;
    
    // Fill the subset sum array
    for (int num : arr) {
        for (int j = sum; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    
    // The last element in the array will contain the result
    return dp[sum];
}
```
