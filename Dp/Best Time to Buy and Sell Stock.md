***Problem:***
```
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
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
#include <limits>

int maxProfit(const std::vector<int>& prices) {
    // Edge case: if there are less than two prices, we can't make a transaction
    if (prices.size() < 2) return 0;

    int min_price = std::numeric_limits<int>::max();
    int max_profit = 0;       // Initialize max profit as 0

    // Traverse through the prices array
    for (int price : prices) {
        // Update the minimum price seen so far
        min_price = std::min(min_price, price);

        // Calculate the potential profit if we sell at the current price
        int profit = price - min_price;

        // Update the maximum profit if the current profit is greater
        max_profit = std::max(max_profit, profit);
    }

    return max_profit;  // Return the maximum profit
}
```


***Testcases:***
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```
