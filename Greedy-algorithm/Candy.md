***Problem:***
```
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
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
#include <iostream>

int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;  // No children, no candies.
    
    vector<int> candies(n, 1);  // Initially give each child 1 candy.
    
    // Left to right pass: ensure children with higher ratings get more candies than the left neighbor.
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    // Right to left pass: ensure children with higher ratings get more candies than the right neighbor.
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);  // Avoid reducing candy count if already adjusted.
        }
    }
    
    // The result is the sum of candies for all children.
    return accumulate(candies.begin(), candies.end(), 0);
}
```


***Testcases:***
```
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
```

```
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
```
