# Ways To Make Coin Change

**Problem statement:** The original `.cpp` file contains an implementation but does not include a complete problem statement. The title is taken from the source filename; consult the original problem source for exact wording, constraints, and examples.

**C++ implementation:**
```cpp

long long int count(int coins[], int N, int sum) {
    // Create a vector to store the number of ways to make change for each value
    vector<long long> dp(sum + 1, 0);
    
    // Base case: There is 1 way to make change for 0
    dp[0] = 1;
    
    // Iterate over each coin denomination
    for (int i = 0; i < N; i++) {
        // Calculate the number of ways to make change for each value
        for (int j = coins[i]; j <= sum; j++) {
            // Add the number of ways to make the remaining value
            dp[j] += dp[j - coins[i]];
        }
    }
    
    // Return the total number of ways to make change for the given value
    return dp[sum];
}
```
