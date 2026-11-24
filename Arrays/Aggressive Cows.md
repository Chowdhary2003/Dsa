***Problem:***
```
Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.
```



***Complexity:***
```
       Time Complexity: O(n log n + n log(maxDist))
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Check if it's possible to place k cows with at least 'minDist' between them
bool canPlaceCows(const std::vector<int>& stalls, int k, int minDist) {
    int count = 1; // Place the first cow in the first stall
    int lastPlaced = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPlaced >= minDist) {
            ++count;
            lastPlaced = stalls[i];
            if (count == k) return true; // Early exit
        }
    }

    return false;
}

int maxMinDistance(std::vector<int>& stalls, int k) {
    std::sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();
    int best = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, k, mid)) {
            best = mid;      // Possible to place → try for more
            low = mid + 1;
        } else {
            high = mid - 1;  // Too tight → reduce distance
        }
    }

    return best;
}
```


***Testcases:***
```
Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

Output: 3

Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.
```

```
Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]

Output: 5

Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions [1, 6]. 
```
