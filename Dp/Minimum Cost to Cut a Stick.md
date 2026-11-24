***Problem:***
```
Given a wooden stick of length n units. The stick is labelled from 0 to n.

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.
```



***Complexity:***
```
       Time Complexity: O(k^3)
       Space Complexity: O(k^2)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Add the endpoints of the stick (0 and n) to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());  // Sort the cuts
        
        // Create a DP table, initialized to 0
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));

        // Fill the DP table
        for (int length = 2; length < size; ++length) {
            for (int i = 0; i + length < size; ++i) {
                int j = i + length;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    // Cost of cutting between cuts[i] and cuts[j], plus the subproblem costs
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }

        return dp[0][size - 1];
    }
};
```


***Testcases:***

![Screenshot 2025-05-22 145141](https://github.com/user-attachments/assets/5ee8dc5f-e6ae-488f-be15-945b579b5268)


```
Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
```
