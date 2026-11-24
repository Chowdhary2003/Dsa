
### GFG


***Problem :***
```
The span of the Ninja Coin price on an ith day is defined as the maximum number of consecutive days (starting from the ith day and going backward) for which the price of a Ninja Coin was less than or equal to its price at ith day.
```

***Complexity :***
```
    Time Complexity : O(N)
    Space Complexity : O(N)
```


***Code :***
```cpp
#include <vector>
#include <stack>

vector<int> calculateSpan(const std::vector<int>& prices) {
    int n = prices.size();       // Get the number of days (size of prices array)
    vector<int> span(n);    // Vector to store the span for each day
    stack<int> s;          // Stack to store indices of prices in a way that helps calculate the span

    // Iterate over each day
    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the price at the index on top of the stack is less than or equal to today's price
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();  // Pop the stack until we find a price greater than today's price
        }
        
        // If the stack is empty, it means no price is greater than today's price, so span is i + 1
        // Otherwise, the span is the difference between today’s day (i) and the day of the last higher price
        span[i] = s.empty() ? (i + 1) : (i - s.top());
        
        // Push the index of today's price onto the stack
        s.push(i);
    }

    // Return the computed spans
    return span;
}
```


***Testcases :***
```
Sample Input :
3
1 1 1
5
4 2 3 3 6

Sample Output :
1 2 3
1 1 2 3 5
Explanation of sample input :
In the first test case, the price of Ninja Coin is the same for all three consecutive days, so its span at ith day will be the number of days till ‘i’.
```





### Leet


***Problem:***
```
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

- For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
- Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.

Implement the StockSpanner class:
- StockSpanner() Initializes the object of the class.
- int next(int price) Returns the span of the stock's price given that today's price is price.
```



***Complexity:***
```
       Time Complexity: O(1)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <stack>
#include <utility>

class StockSpanner {
private:
    // Stack holds pairs of (price, span)
    std::stack<std::pair<int, int>> stk;

public:
    StockSpanner() = default;

    int next(int price) {
        int span = 1;  // At least today's span is 1

        // Pop while the current price >= stack top's price
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second; // Accumulate the span
            stk.pop();
        }

        stk.emplace(price, span);
        return span;
    }
};
```


***Testcases:***
```
Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
```







