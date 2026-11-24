***Problem:***
```
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
```



***Complexity:***
```
       Time Complexity: O((V + E) log V)
       Space Complexity: O(V + E)
```



***Code:***
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Build the graph as an adjacency list
    vector<vector<pair<int, int>>> graph(n + 1); // 1-based indexing
    for (const auto& edge : times) {
        int u = edge[0], v = edge[1], w = edge[2];
        graph[u].emplace_back(v, w);
    }

    // Min-heap priority queue: (time, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.emplace(0, k);

    vector<int> dist(n + 1, numeric_limits<int>::max());
    dist[k] = 0;

    while (!minHeap.empty()) {
        auto [time, u] = minHeap.top();
        minHeap.pop();

        if (time > dist[u]) continue; // Skip if a better path is already found

        for (const auto& [v, w] : graph[u]) {
            if (dist[v] > time + w) {
                dist[v] = time + w;
                minHeap.emplace(dist[v], v);
            }
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == numeric_limits<int>::max()) return -1;
        maxTime = max(maxTime, dist[i]);
    }

    return maxTime;
}
```


***Testcases:***

![Screenshot 2025-05-20 150811](https://github.com/user-attachments/assets/3dbef81c-3a8a-4e56-bc65-1df6732cdc41)

