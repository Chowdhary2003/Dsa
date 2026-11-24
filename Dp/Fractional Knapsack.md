***Problem:***
```
Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.

Return the maximum value as a double, rounded to 6 decimal places.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

struct Item {
    double value;
    double weight;

    // Compute value/weight ratio
    double ratio() const {
        return value / weight;
    }
};

double fractionalKnapsack(const vector<int>& val, const vector<int>& wt, int capacity) {
    int n = val.size();
    vector<Item> items(n);

    // Build items from input arrays
    for (int i = 0; i < n; ++i) {
        items[i] = {static_cast<double>(val[i]), static_cast<double>(wt[i])};
    }

    // Sort by descending value-to-weight ratio
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio() > b.ratio();
    });

    double totalValue = 0.0;
    double remainingCapacity = static_cast<double>(capacity);

    for (const auto& item : items) {
        if (remainingCapacity <= 0)
            break;

        if (item.weight <= remainingCapacity) {
            // Take full item
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            // Take fraction of item
            totalValue += item.ratio() * remainingCapacity;
            remainingCapacity = 0;
        }
    }

    // Round to 6 decimal places
    return round(totalValue * 1e6) / 1e6;
}
```


***Testcases:***
```
Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
```

```
Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given capacity of sack.
```

```
Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
Output: 60.000000
Explanation: In this case, the knapsack capacity exceeds the combined weight of all items (5 + 10 + 15 = 30). Therefore, we can take all items completely, yielding a total maximum value of 10 + 20 + 30 = 60.000000.
```
