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
#include <algorithm> // For std::min, std::max

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) return 0; // No prices means no profit
    
    int minPrice = prices[0]; // Track the lowest buying price seen so far
    int maxProfit = 0;        // Track the max profit found
    
    for (int price : prices) {
        // Update minPrice to the lowest price up to the current day
        minPrice = std::min(minPrice, price);
        
        // Calculate potential profit if selling today at current price
        // Since minPrice is updated first, this is effectively the profit
        // from buying at or before today and selling today
        int profit = price - minPrice;
        
        // Update maxProfit if this profit is better
        maxProfit = std::max(maxProfit, profit);
    }
    
    return maxProfit;
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
