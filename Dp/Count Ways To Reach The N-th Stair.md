# Count Ways To Reach The N-th Stair

**Problem statement:** The original `.cpp` file contains an implementation but does not include a complete problem statement. The title is taken from the source filename; consult the original problem source for exact wording, constraints, and examples.

**C++ implementation:**
```cpp
/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where ‘N’ is the point to reach given in the input.
*/

int countDistinctWays(int nStairs) {
    
    // Initialize the variable 'mod'.
    const int mod = 1000000007;

    // Create an array 'dp' of length '2' with intial value '1'.
    vector<int> dp(2, 1);

    // Checking if 'nStairs' is less than or equal to '1', 
    // Because in that case there is no need for further calculation.
    if(nStairs <= 1) {

        return dp[nStairs];
    }

    // Iterate on the range '[2, nStairs]'.
    for (int currStep = 2; currStep <= nStairs; currStep++) {

        // Calculate ways to reach 'currStep'th stair.
        int currStepWays = (dp[0] + dp[1]) % mod;

        // Update 'dp' array.
        dp[0] = dp[1];

        dp[1] = currStepWays;
    }

    return dp[1];
}
```
