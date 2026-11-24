***Problem:***
```
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x₁ - x₂)² + (y₁ - y₂)²).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
```



***Complexity:***
```
       Time Complexity: O(n log k)
       Space Complexity: O(k)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Custom comparator for max-heap (by squared distance)
        auto dist = [](const vector<int>& p) {
            return p[0] * p[0] + p[1] * p[1];
        };

        // Max-heap to keep k closest points (farthest at top)
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const auto& point : points) {
            int d = dist(point);
            maxHeap.emplace(d, point);
            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove farthest
            }
        }

        // Extract result from heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
```


***Testcases:***

<img width="1293" height="1248" alt="Screenshot 2025-07-13 092104" src="https://github.com/user-attachments/assets/ba8da803-173e-4903-8c92-4b1b9a8ebbf9" />


```
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
```
