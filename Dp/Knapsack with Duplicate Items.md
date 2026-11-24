***Problem:***
```
Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

Note: Each item can be taken any number of times.
```



***Complexity:***
```
       Time Complexity: O(n * capacity)
       Space Complexity: O(capacity)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

// C++17 and above
int unboundedKnapsack(int capacity, const std::vector<int>& wt, const std::vector<int>& val) {
    int n = wt.size();
    std::vector<int> dp(capacity + 1, 0); // dp[w] = max value for weight w

    for (int w = 0; w <= capacity; ++w) {
        for (int i = 0; i < n; ++i) {
            if (wt[i] <= w) {
                dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
    }
    return dp[capacity];
}
```


***Testcases:***
```
Input: val = [1, 1], wt = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.
```

```
Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
Output: 48
Explanation: The optimal choice is to pick the 1st element 8 times.
```

```
Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
Output: 0
Explanation: We can't pick any element .hence, total profit is 0.
```
