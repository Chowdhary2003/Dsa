***Problem:***
```
Given an integer array of coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that are needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. There are infinite numbers of coins of each type
```



***Complexity:***
```
       Time Complexity: O(amount * N)
       Space Complexity: O(amount)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <limits>

int coinChange(const std::vector<int>& coins, int amount) {
    constexpr int INF = std::numeric_limits<int>::max() - 1; // avoid overflow
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0; // base case: zero coins to make amount 0

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            if (dp[i - coin] != INF) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}
```


***Testcases:***
```
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1. We need 3 coins to make up the amount 11.
```

```
Input: coins = [2, 5], amount = 3
Output: -1
Explanation: It's not possible to make amount 3 with coins 2 and 5. Since we can't combine the coin 2 and 5 to make the amount 3, the output is -1.
```
