***Problem:***
```
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
-  After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).


Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
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

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        int hold = -prices[0]; // Bought on day 0
        int sold = 0;          // Profit after selling
        int rest = 0;          // Resting/cooldown state

        for (int i = 1; i < n; ++i) {
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_rest = rest;

            hold = std::max(prev_hold, prev_rest - prices[i]); // Buy or hold
            sold = prev_hold + prices[i];                      // Sell
            rest = max(prev_rest, prev_sold);             // Rest or cooldown
        }

        // The max profit is in the "not holding" states
        return max(sold, rest);
    }
};
```


***Testcases:***
```
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

```
Input: prices = [1]
Output: 0
```
