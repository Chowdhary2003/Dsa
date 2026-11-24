***Problem:***
```
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
```



***Complexity:***
```
       Time Complexity: O(E * log V)
       Space Complexity: O(E)
```



***Code:***
```cpp
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adjacency list: from -> vector of (to, price)
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            graph[u].emplace_back(v, w);
        }

        // Min-heap priority queue: (total cost, current city, number of stops)
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, src, 0);

        // Track the minimum number of stops to reach each city
        vector<int> minStops(n, numeric_limits<int>::max());
        minStops[src] = 0;

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst) return cost;
            if (stops > k || stops > minStops[u]) continue;

            minStops[u] = stops;

            for (auto& [v, w] : graph[u]) {
                pq.emplace(cost + w, v, stops + 1);
            }
        }

        return -1;
    }
};
```


***Testcases:***


![Screenshot 2025-05-20 150347](https://github.com/user-attachments/assets/38424b75-6473-4910-a17c-42cb11191151)



![Screenshot 2025-05-20 150356](https://github.com/user-attachments/assets/584097fe-ce65-45ea-a740-ff5a4677d19a)
