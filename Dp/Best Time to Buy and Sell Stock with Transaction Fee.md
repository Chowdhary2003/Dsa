***Problem:***
```
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:
- You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
- The transaction fee is only charged once for each stock purchase and sale.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices, int fee) {
    if (prices.empty()) return 0;

    int cash = 0;                  // Max profit when not holding stock
    int hold = -prices[0];        // Max profit when holding stock (after buying on day 0)

    for (size_t i = 1; i < prices.size(); ++i) {
        cash = std::max(cash, hold + prices[i] - fee); // Sell today if profitable
        hold = std::max(hold, cash - prices[i]);       // Buy today if beneficial
    }

    return cash; // Max profit ends in 'not holding' state
}
```


***Testcases:***
```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```
