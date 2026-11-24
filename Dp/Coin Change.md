***Problem:***
```
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
```



***Complexity:***
```
       Time Complexity: O(amount * n)
       Space Complexity: O(amount)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <limits>

int coinChange(const vector<int>& coins, int amount) {
    const int INF = amount + 1; // Safe upper bound for DP values
    vector<int> dp(amount + 1, INF);
    dp[0] = 0; // Base case: 0 coins to make amount 0

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}
```


***Testcases:***
```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

```
Input: coins = [2], amount = 3
Output: -1
```

```
Input: coins = [1], amount = 0
Output: 0
```
