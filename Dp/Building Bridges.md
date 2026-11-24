***Problem:***
```
Consider a 2-D map with a horizontal river passing through its center. There are n cities on the southern bank with x-coordinates a(1) … a(n) and n cities on the northern bank with x-coordinates b(1) … b(n). You want to connect as many north-south pairs of cities as possible with bridges such that no two bridges cross. When connecting cities, you can only connect city a(i) on the northern bank to city b(i) on the southern bank. Maximum number of bridges that can be built to connect north-south pairs with the above mentioned constraints.
```

<img src="https://github.com/user-attachments/assets/ff8b7523-f19d-473f-ae55-eb802bd9bab5" width="500" />


```
The values in the upper bank can be considered as the northern x-coordinates of the cities and the values in the bottom bank can be considered as the corresponding southern x-coordinates of the cities to which the northern x-coordinate city can be connected.
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

using namespace std;

int maxBridges(const vector<int>& north, const vector<int>& south) {
    int n = (int)north.size();
    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; ++i) {
        cities[i] = {north[i], south[i]};
    }
    // Sort pairs by northern coordinate
    sort(cities.begin(), cities.end());

    // Extract southern coordinates in sorted northern order
    vector<int> sortedSouth(n);
    for (int i = 0; i < n; ++i) {
        sortedSouth[i] = cities[i].second;
    }

    // Find length of LIS in sortedSouth using patience sorting (binary search)
    vector<int> lis;
    for (int val : sortedSouth) {
        // Find insertion point for val in lis
        auto it = lower_bound(lis.begin(), lis.end(), val);
        if (it == lis.end()) lis.push_back(val);
        else *it = val;
    }
    return (int)lis.size();
}
```


***Testcases:***
```
Input : 6 4 2 1
        2 3 6 5
Output : Maximum number of bridges = 2
Explanation: Let the north-south x-coordinates
be written in increasing order.

1  2  3  4  5  6
  \  \
   \  \        For the north-south pairs
    \  \       (2, 6) and (1, 5)
     \  \      the bridges can be built.
      \  \     We can consider other pairs also,
       \  \    but then only one bridge can be built 
        \  \   because more than one bridge built will
         \  \  then cross each other.
          \  \
1  2  3  4  5  6 
```

```
Input : 8 1 4 3 5 2 6 7 
        1 2 3 4 5 6 7 8
Output : Maximum number of bridges = 5
```
