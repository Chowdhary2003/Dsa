***Problem:***
```
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) return 0;

    const int n = static_cast<int>(prices.size());
    std::vector<int> leftProfits(n, 0);  // Max profit in [0..i]
    std::vector<int> rightProfits(n, 0); // Max profit in [i..n-1]

    // Pass 1: left to right
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = std::min(minPrice, prices[i]);
        leftProfits[i] = std::max(leftProfits[i - 1], prices[i] - minPrice);
    }

    // Pass 2: right to left
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = std::max(maxPrice, prices[i]);
        rightProfits[i] = std::max(rightProfits[i + 1], maxPrice - prices[i]);
    }

    // Combine both profits
    int maxTotalProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxTotalProfit = std::max(maxTotalProfit, leftProfits[i] + rightProfits[i]);
    }

    return maxTotalProfit;
}
```


***Testcases:***
```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
```

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```
