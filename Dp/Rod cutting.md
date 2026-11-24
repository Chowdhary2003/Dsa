# Rod cutting

**Problem statement:** The original `.cpp` file contains an implementation but does not include a complete problem statement. The title is taken from the source filename; consult the original problem source for exact wording, constraints, and examples.

**C++ implementation:**
```cpp

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    // Create a vector to store the current DP state
    vector<int> cur(W + 1, 0);

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        cur[i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    // Iterate over each item
    for (int ind = 1; ind < n; ind++) {
        // Iterate over each capacity from 0 to W
        for (int cap = 0; cap <= W; cap++) {
            // Calculate the maximum value without taking the current item
            int notTaken = cur[cap];

            // Calculate the maximum value by taking the current item
            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];

            // Store the maximum value in the current DP state
            cur[cap] = max(notTaken, taken);
        }
    }

    // Return the maximum value considering all items and the knapsack capacity
    return cur[W];
}
```
