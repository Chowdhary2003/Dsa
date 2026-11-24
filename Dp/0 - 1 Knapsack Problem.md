***Problem:***
```
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.
```



***Complexity:***
```
       Time Complexity: O(n × W)
       Space Complexity: O(W)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

// Assumes: weights.size() == values.size()
int knapsack01(int W, const std::vector<int>& weights, const std::vector<int>& values) {
    const int n = weights.size();
    std::vector<int> dp(W + 1, 0); // dp[w] = max value for weight w

    for (int i = 0; i < n; ++i) {
        int wt = weights[i];
        int val = values[i];
        // Iterate in reverse to avoid using the same item more than once
        for (int w = W; w >= wt; --w) {
            dp[w] = std::max(dp[w], dp[w - wt] + val);
        }
    }
    return dp[W]; // Max value at full capacity
}
```


***Testcases:***
```
Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
```

```
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
```

```
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
```
