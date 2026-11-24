***Problem:***
```
You have n items; the i-th item has value val[i] and weight wt[i].
A knapsack can carry at most capacity units of weight.

You may take any fraction of an item (i.e. split items).
Return the maximum total value that can be placed in the knapsack, rounded to exactly 6 decimal places.
```



***Complexity:***
```
       Time Complexity: O(n log n)
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>      // for std::setprecision
#include <limits>       // for std::numeric_limits

struct Item {
    double value;
    double weight;

    double ratio() const {
        if (weight == 0.0) {
            // Handle zero-weight items safely
            return value > 0.0 ? std::numeric_limits<double>::infinity() : 0.0;
        }
        return value / weight;
    }
};

// Comparator: sort by descending value-to-weight ratio
static bool compare(const Item& a, const Item& b) {
    return a.ratio() > b.ratio();
}

double fractionalKnapsack(const std::vector<double>& val, const std::vector<double>& wt, double capacity) {
    const int n = val.size();
    std::vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        items[i] = {val[i], wt[i]};
    }

    std::sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    double remainingCapacity = capacity;

    for (const auto& item : items) {
        if (remainingCapacity <= 0.0)
            break;

        if (item.weight == 0.0) {
            // Zero-weight item: if it has positive value, take it (doesn't affect capacity)
            if (item.value > 0.0) {
                totalValue += item.value;
            }
            continue;
        }

        if (item.weight <= remainingCapacity) {
            // Take whole item
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            // Take fractional part
            totalValue += item.ratio() * remainingCapacity;
            remainingCapacity = 0.0;
        }
    }

    return totalValue;
}
```


***Testcases:***
```
Input: val = [60,100,120], wt = [10,20,30], capacity = 50
Output: 240.000000
Explanation:
 • Take item 0 (w=10, v=60)
 • Take item 1 (w=20, v=100)
 • Take 2⁄3 of item 2 (w=20, v=80)
Total value = 60 + 100 + 80 = 240
```

```
Input: val = [60,100], wt = [10,20], capacity = 50
Output: 160.000000
Explanation: Both items fit entirely (total weight 30 ≤ 50).
```
