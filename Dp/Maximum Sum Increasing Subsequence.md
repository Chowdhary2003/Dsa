# Maximum Sum Increasing Subsequence

**Problem statement:** The original `.cpp` file contains an implementation but does not include a complete problem statement. The title is taken from the source filename; consult the original problem source for exact wording, constraints, and examples.

**C++ implementation:**
```cpp
/*

    Time Complexity: O(N log N)

    Space Complexity: O(N)

    Where N is the number of dumbbells in the rack.

*/

int maxIncreasingDumbbellsSum(vector<int>& rack, int n) {

    vector<int> dp; // Stores the elements of the increasing subsequence

    // Add the first element of the rack to the dp vector

    dp.push_back(rack[0]);

    // Iterate through the remaining elements of the rack

    for (int i = 1; i < n; i++) {

        if (rack[i] > dp.back()) {

            // If the current element is greater than the last element in dp,

            // append it to the end of dp

            dp.push_back(rack[i]);

        } else {

            // If the current element is not greater, find the position where it should be inserted or replaced

            int idx = lower_bound(dp.begin(), dp.end(), rack[i]) - dp.begin();

            dp[idx] = rack[i]; // Replace the element at idx with the current element

        }

    }

    // Calculate the total weight by summing up all the elements in dp

    int totalWeight = accumulate(dp.begin(), dp.end(), 0);

    return totalWeight;

}

```
